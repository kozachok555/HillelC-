#pragma once
#include <queue>
#include <mutex>
#include <condition_variable>

class SafeQueue {
public:
    SafeQueue() = default;
    ~SafeQueue() = default;

    SafeQueue(const SafeQueue&) = delete;
    SafeQueue(SafeQueue&&) = delete;
    SafeQueue& operator=(const SafeQueue&) = delete;
    SafeQueue& operator=(SafeQueue&&) = delete;

    void push(int value);
    bool pop(int& value);
    void close();
    void getQueue(std::queue<int>& q);
private:
    std::queue<int> queue;
    std::mutex mtx;
    std::condition_variable cv;
    bool closed = false;
};
