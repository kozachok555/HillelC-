#include "SafeQueue.h"

void SafeQueue::push(int value) {
    std::lock_guard<std::mutex> lock(mtx);
    queue.push(value);
    cv.notify_one();
}

bool SafeQueue::pop(int& value) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [this]() { return !queue.empty() || closed; });

    if (queue.empty()) return false;

    value = queue.front();
    queue.pop();
    return true;
}

void SafeQueue::close() {
    std::lock_guard<std::mutex> lock(mtx);
    closed = true;
    cv.notify_all();
}
void SafeQueue::getQueue(std::queue<int>& q) {
    std::lock_guard<std::mutex> lock(mtx);
    q = queue;
}
