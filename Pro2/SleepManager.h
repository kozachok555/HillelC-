#pragma once
#include <queue>
#include <vector>
#include <mutex>
#include <memory>

class Worker;
struct Logger;

class SleepManager {
public:
    SleepManager(std::vector<std::unique_ptr<Worker>>* workers, Logger* logger, int nWorkers);

    void onSleep(int workerId);
    void wakeFirst();
    void wakeAll();

private:
    std::vector<std::unique_ptr<Worker>>* workers_;
    Logger* logger_;

    std::queue<int> fifo_;
    std::vector<bool> inFifo_;
    std::mutex mtx_;
};
