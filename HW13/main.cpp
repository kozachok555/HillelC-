#include <iostream>
#include "build/Header.h"


int main() {
	/*size_t size = 10;*/
	/*int* dyVector = nullptr;
	create_vector(dyVector, size, 2);
	create_vector(dyVector, 10);

	for (int count = 0; count < size; ++count) {
		std::cout << dyVector[count];
	}
	delete_vector(dyVector);*/

	//int* dyVector = create_vector(10, 2);
	//int* dyVector1 = create_vector(10);

	//for (int count = 0; count < size; ++count) {
	//	std::cout << dyVector[count];
	//}
	//delete_vector(dyVector);
	//delete_vector(dyVector1);

	/*int* dyVector = create_vector(10, 2);
	int* dyVector1 = create_vector(10);
	copy_vector(dyVector1, dyVector, 2);

	for (int count = 0; count < size; ++count) {
		std::cout << dyVector1[count];
	}
	delete_vector(dyVector);
	delete_vector(dyVector1);*/

	//unsigned size = 10;
	//int* dyVector = create_vector(size, 2);
	//push_back_in_vector(dyVector, size, 5);

	//for (int count = 0; count < size + 1; ++count) {
	//	std::cout << dyVector[count];
	//}
	//delete_vector(dyVector);

	unsigned size = 10;
	int* dyVector = create_vector(size, 2);
	int& item = at_vector(dyVector, 2);
	item = 10;

	for (int count = 0; count < size + 1; ++count) {
		std::cout << dyVector[count];
	}
	delete_vector(dyVector);

}