#include "SleepManager.h"
#include "Worker.h"
#include "Logger.h"

SleepManager::SleepManager(std::vector<std::unique_ptr<Worker>>* workers, Logger* logger, int nWorkers)
    : workers_(workers), logger_(logger), inFifo_(nWorkers, false) {
}

void SleepManager::onSleep(int workerId) {
    std::lock_guard<std::mutex> lg(mtx_);
    if (!inFifo_[workerId]) {
        fifo_.push(workerId);
        inFifo_[workerId] = true;
    }
}

void SleepManager::wakeFirst() {
    int id = -1;

    {
        std::lock_guard<std::mutex> lg(mtx_);
        while (!fifo_.empty()) {
            int cand = fifo_.front();
            fifo_.pop();
            inFifo_[cand] = false;

            if ((*workers_)[cand]->isSleeping()) {
                id = cand;
                break;
            }
        }
    }

    if (id == -1) return;

    (*workers_)[id]->wakeUp();
    logger_->incWake0(id);
}

void SleepManager::wakeAll() {
    std::vector<int> ids;

    {
        std::lock_guard<std::mutex> lg(mtx_);
        while (!fifo_.empty()) {
            int id = fifo_.front();
            fifo_.pop();
            inFifo_[id] = false;
            ids.push_back(id);
        }
    }

    for (int id : ids) {
        if ((*workers_)[id]->isSleeping()) {
            (*workers_)[id]->wakeUp();
            logger_->incWake21(id);
        }
    }
}
