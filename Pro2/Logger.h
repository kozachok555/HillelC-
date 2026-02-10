#pragma once
#include <vector>
#include <mutex>
#include <iostream>

struct Logger {
    explicit Logger(int n)
        : sleepCount(n, 0),
        wakeCount(n, 0),
        wakeBy0(n, 0),
        wakeBy21(n, 0) {
    }

    std::vector<int> sleepCount;
    std::vector<int> wakeCount;
    std::vector<int> wakeBy0;
    std::vector<int> wakeBy21;

    std::mutex mtx;

    void incSleep(int id) {
        std::lock_guard<std::mutex> lg(mtx);
        sleepCount[id]++;
    }

    void incWake0(int id) {
        std::lock_guard<std::mutex> lg(mtx);
        wakeCount[id]++;
        wakeBy0[id]++;
    }

    void incWake21(int id) {
        std::lock_guard<std::mutex> lg(mtx);
        wakeCount[id]++;
        wakeBy21[id]++;
    }

    void report(const std::vector<int>& sleepEndIds) {
        std::lock_guard<std::mutex> lg(mtx);

        std::cout << "\n=== LOGGER REPORT ===\n";
        std::cout << "sleep end count: " << sleepEndIds.size() << "\n";
        std::cout << "sleep end ids: [";
        for (size_t i = 0; i < sleepEndIds.size(); ++i) {
            std::cout << sleepEndIds[i] << (i + 1 < sleepEndIds.size() ? ", " : "");
        }
        std::cout << "]\n\n";

        std::cout << "per thread metrics:\n";
        std::cout << "id | sleep_count | wake_count | wake_by_0 | wake_by_21\n";
        std::cout << "------------------------------------------------------\n";
        for (int i = 0; i < (int)sleepCount.size(); ++i) {
            std::cout << i << "  | "
                << sleepCount[i] << "          | "
                << wakeCount[i] << "         | "
                << wakeBy0[i] << "         | "
                << wakeBy21[i] << "\n";
        }
        std::cout << "=====================\n";
    }
};
