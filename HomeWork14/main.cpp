#include <iostream>

class MyVector
{
public:
	MyVector(MyVector &&) = delete;
	MyVector &operator-(MyVector &&) = delete;
	int &operator[](const unsigned index)
	{
		return data_[index];
	};

	MyVector(const MyVector &other)
	{
		capacity_ = other.capacity_;
		size_ = other.size_;
		data_ = other.data_;

		if (!other.capacity_)
		{
			return;
		}
		data_ = new int[other.capacity_];
		capacity_ = other.capacity_;
		size_ = other.size_;
		for (size_t i = 0; i < size_; i++)
		{
			data_[i] = other.data_[i];
		};
	};
	MyVector &operator=(const MyVector &other)
	{
		if (this == &other)
		{
			return;
		};
		if (data_)
		{
			delete data_;
			data_ = nullptr;
		};
		capacity_ = other.capacity_;
		size_ = other.size_;
		if (!other.capacity_)
		{
			return;
		};

		int *data_ = new int[other.capacity_];
		for (size_t i = 0; i < size_; ++i)
		{
			data_[i] = other.data_[i];
		};
	};

	MyVector(const unsigned size, const int valueByDefault = 0)
	{
		size_ = size;
		capacity_ = size * 2;
		if (size > 0)
		{
			data_ = new int[size];
		}
	};
	~MyVector()
	{
		if (data_ != nullptr)
		{
			delete[] data_;
		}
	};
	void push_back(const int newValue)
	{
		if (capacity_ > size_)
		{
			data_[size_] = newValue;
			++size_;
			return;
		}

		capacity_ = size_ * 2;
		int *copy = new int[capacity_];
		for (size_t i = 0; i < size_; ++i)
		{
			copy[i] = data_[i];
		};
		copy[size_] = newValue;
		++size_;

		delete[] data_;
		data_ = copy;
	};

private:
	unsigned size_ = 0;
	int *data_ = nullptr;
	int capacity_ = 0;
};
int main()
{
	MyVector vec(5);
	vec.push_back(10);
	std::cout << vec[5] << std::endl;
};