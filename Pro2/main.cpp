#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>

void generatorNumbers(int N) {
	std::srand(std::time(0));
	int max = 100;
	int min = -100;
	for (int i = 0; i < N; ++i) {
		int random_number = std::rand() % (max - min + 1) + min;
		dispathcher(random_number);
	}
}
void dispathcher(int number) {

}
int main() {
	std::cout << "Enter the number of random integers to generate: ";
	int N;
	std::cin >> N;
	generatorNumbers(N);
	return 0;
}