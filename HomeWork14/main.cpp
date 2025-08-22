#include <iostream>

class MyVector {
public:
	int& operator[](const unsigned index) {
		return data[index];
	};

	MyVector(const MyVector&) = delete;
	MyVector operator=(const MyVector&) = delete;

	MyVector(const unsigned size, const int valueByDefault = 0) {
		m_size = size;
		if (size > 0) {
			data = new int[size];
		}
	};
	~MyVector() {
		if (data != nullptr) {
			delete[] data;
		}
	};
	void push_back(const unsigned size, const int newValue) {
		int* copy = new int[size + 1];
		for (unsigned i = 0; i < size; i++) {
			copy[i] = data[i];
		}
		copy[size] = newValue;
		m_size = size + 1;

		delete[] data;
		data = copy;
	};

private:
	unsigned m_size = 0;
	int* data = nullptr;
};
int main() {
	MyVector vec(5);
	vec.push_back(5, 10);
	std::cout << vec[5] << std::endl;
};