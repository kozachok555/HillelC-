#pragma once

#include <atomic>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>
#include "Logger.h"
#include "SleepManager.h"
#include "SafeQueue.h"

class SleepManager;
struct Logger;

class Worker {
public:
    Worker(int id, SleepManager* sm, Logger* logger);
    ~Worker();

    Worker(const Worker&) = delete;
    Worker& operator=(const Worker&) = delete;

    Worker(Worker&&) = delete;
    Worker& operator=(Worker&&) = delete;

    void start();
    void join();

    void pushTask(int x);
    void close();

    void wakeUp();           
    bool isSleeping() const; 
    bool endedSleeping() const;

private:
    void run();

private:
    int workerId_;
    SafeQueue tasks_;
    std::thread workerThread_;

    SleepManager* sm_;
    Logger* logger_;

    std::atomic<bool> sleeping_{ false };
    std::atomic<bool> stopping_{ false };
    std::atomic<bool> endedSleeping_{ false };

    std::mutex mtx_;
    std::condition_variable cv_;
};
