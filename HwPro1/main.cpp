#include <iostream>
class UniquePtr {
	int* ptr = nullptr;
public:
	UniquePtr(const UniquePtr&) = delete;
	UniquePtr& operator=(const UniquePtr&) = delete;
	UniquePtr(UniquePtr&&) = delete;
	UniquePtr& operator=(UniquePtr&&) = delete;

	UniquePtr(int* p = nullptr) : ptr(p) {};
	UniquePtr(int value = 0)
		: ptr(new int(value)) {
	};
	~UniquePtr() {
		delete ptr;
	};
	int getValue() const {
		if (!ptr)
			throw std::runtime_error("Accessing null IntPtr");
		return *ptr;
	}
	int& operator*() const {
		if (!ptr)
			throw std::runtime_error("Dereferencing null IntPtr");
		return *ptr;
	}
	int* operator->() const {
		if (!ptr)
			throw std::runtime_error("Accessing null IntPtr");
		return ptr;
	}


	bool isValid() const {
		return ptr != nullptr;
	}
	operator bool() const {
		return ptr != nullptr;
	}
	void reset(int* p = nullptr) {
		if (ptr != p) {
			delete ptr;
			ptr = p;
		}
		else {
			delete ptr;
			ptr = nullptr;
		}
	}


};

int main() {
	int value = 42;
	UniquePtr p(value);
	if(p) {
		std::cout << "Value: " << *p << std::endl;
	} else {
		std::cout << "Pointer is null." << std::endl;
	}
	if(p.isValid()) {
		std::cout << "Pointer is valid." << std::endl;
	} else {
		std::cout << "Pointer is null." << std::endl;
	}
	p.reset(new int(5));
	std::cout << p.getValue() << std::endl;
	return 0;
};