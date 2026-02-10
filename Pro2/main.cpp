#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <vector>
#include <memory>

#include "SafeQueue.h"
#include "Worker.h"
#include "Logger.h"
#include "SleepManager.h"

std::vector<int> generatorNumbers(int N) {
	std::vector<int> numbers;
	std::srand(std::time(0));
	int max = 100;
	int min = -100;
	for (int i = 0; i < N; ++i) {
		int random_number = std::rand() % (max - min + 1) + min;
		numbers.emplace_back(random_number);
	}
	return numbers;
}
void dispatcher(SafeQueue& qNumbers,
	std::vector<std::unique_ptr<Worker>>& workers,
	SleepManager& sm){
	size_t rrIndex = 0;
	int x = 0;
	while (qNumbers.pop(x)) {
		if (x == 0) {
			sm.wakeFirst();
			continue;
		};
		if (x == 21) {
			sm.wakeAll();
			continue;
		};
		workers[rrIndex]->pushTask(x);
		rrIndex = (rrIndex + 1) % workers.size();
	};
	for (auto& worker : workers) worker->close();

}
void sender(const std::vector<int>& numbers, SafeQueue& q) {
	for (int x : numbers) q.push(x);
	q.close();
}

int main() {
    const int gWorkers = 10;

    std::cout << "Enter the number of random integers to generate: ";
    int N = 0;
    std::cin >> N;

    std::vector<int> numbers = generatorNumbers(N);
    SafeQueue q;

    Logger logger(gWorkers);

	std::vector<std::unique_ptr<Worker>> workers;
	workers.reserve(gWorkers);


    SleepManager sm(&workers, &logger);

	for (int i = 0; i < gWorkers; ++i) {
		workers.emplace_back(std::make_unique<Worker>(i, &sm, &logger));
	}
	for (auto& w : workers) {
		w->start();
	}

    std::thread senderThread(sender, std::cref(numbers), std::ref(q));
	std::thread dispatcherThread(dispatcher, std::ref(q), std::ref(workers), std::ref(sm));

    senderThread.join();
    dispatcherThread.join();

	for (auto& w : workers) w->join();

    std::vector<int> sleepEndIds;
    sleepEndIds.reserve(gWorkers);
    for (int i = 0; i < gWorkers; ++i) {
		if (workers[i]->endedSleeping()) {
			sleepEndIds.push_back(i);
		}
    }

    logger.report(sleepEndIds);
    return 0;
}