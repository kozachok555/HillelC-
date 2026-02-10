#include "Worker.h"

Worker::Worker(int id, SleepManager* sm, Logger* logger)
    : workerId_(id), sm_(sm), logger_(logger) {
}

Worker::~Worker() {
  
    if (workerThread_.joinable()) {
        close();
        workerThread_.join();
    }
}

void Worker::start() {
    workerThread_ = std::thread(&Worker::run, this);
}

void Worker::join() {
    if (workerThread_.joinable()) workerThread_.join();
}

void Worker::pushTask(int x) {
    tasks_.push(x);
}

void Worker::close() {
    stopping_.store(true, std::memory_order_relaxed);
    tasks_.close();
    cv_.notify_all();
}

void Worker::wakeUp() {
    sleeping_.store(false, std::memory_order_relaxed);
    cv_.notify_one();
}

bool Worker::isSleeping() const {
    return sleeping_.load(std::memory_order_relaxed);
}

bool Worker::endedSleeping() const {
    return endedSleeping_.load(std::memory_order_relaxed);
}

void Worker::run() {
    int x = 0;
    while (true) {
        if (sleeping_.load(std::memory_order_relaxed)) {
            std::unique_lock<std::mutex> lk(mtx_);
            cv_.wait(lk, [&] {
                return !sleeping_.load(std::memory_order_relaxed) ||
                    stopping_.load(std::memory_order_relaxed);
                });
            if (stopping_.load(std::memory_order_relaxed) &&
                sleeping_.load(std::memory_order_relaxed)) {
                endedSleeping_.store(true, std::memory_order_relaxed);
                break;
            }
        }
        if (!tasks_.pop(x)) {
            endedSleeping_.store(sleeping_.load(std::memory_order_relaxed),
                std::memory_order_relaxed);
            break;
        }
        if (x == 7) {
            sleeping_.store(true, std::memory_order_relaxed);
            logger_->incSleep(workerId_);
            sm_->onSleep(workerId_);
            continue;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}
