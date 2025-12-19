#include <iostream>
class SharedPtr {
private:
	int* ptr;
	unsigned* count;
public:
	SharedPtr(const SharedPtr&&) = delete;
	SharedPtr& operator=(const SharedPtr&&) = delete;

	SharedPtr() : ptr(nullptr), count(nullptr) {};
	SharedPtr(int* p) : ptr(p) {
		if (p) {
			count = new unsigned(1);
		}
		else {
			count = nullptr;
		}
	};
	SharedPtr(int value = 0) :ptr(new int(value)) {
		count = new unsigned(1);
	};
	~SharedPtr()
	{
		release();
	};
	void release()
	{
		if (count)
		{
			--(*count);
			if (*count == 0)
			{
				delete ptr;
				delete count;
			}
		}
		ptr = nullptr;
		count = nullptr;
	}
	SharedPtr(const SharedPtr& other)
	{
		ptr = other.ptr;
		count = other.count;
		if (count) ++(*count);
	}
	SharedPtr& operator=(const SharedPtr& other)
	{
		if (this == &other) return *this;

		release();
		ptr = other.ptr;
		count = other.count;
		if (count) ++(*count);
		return *this;
	};
	bool isValid() const {
		return ptr != nullptr;
	}
	operator bool() const {
		return ptr != nullptr;
	}
	int& operator*() const {
		return *ptr;
	}
	int* operator->() const {
		return ptr;
	}
};
int main() {
	SharedPtr p1(new int(42));
	{
		SharedPtr p2 = p1;
		std::cout << *p2 << std::endl;
		std::cout << p2.isValid() << std::endl;
	}
	return 0;
};