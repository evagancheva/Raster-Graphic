#include "MyString.h"
#include <cstring>
#pragma warning (disable : 4996)

unsigned nextPowerOfTwo(unsigned n)
{
	unsigned step = 1;

	while ((n >> step) > 0) {
		n |= n >> step;
		step <<= 1;
	}

	return n + 1;
}
void MyString::free()
{
	delete[]data;
	data = nullptr;

	capacity = size = 0;
}

void MyString::copyFrom(const MyString& other)
{
	size = other.size;
	capacity = other.capacity;

	data = new char[capacity + 1];
	strcpy(data, other.data);
}

void MyString::moveFrom(MyString&& other)
{
	data = other.data;
	other.data = nullptr;

	size = other.size;
	capacity = other.capacity;

	other.size = other.capacity = 0;

}

void MyString::resize(size_t cap)
{
	char* newData = new char[cap + 1];
	strcpy(newData, data);

	delete[]data;
	data = newData;

	capacity = cap;
}

MyString::MyString(const char* data)
{
	if (!data) {
		return;
	}
	size = strlen(data);
	capacity = std::max((int)nextPowerOfTwo(size), 16) - 1;

	this->data = new char[capacity + 1];
	strcpy(this->data, data);

}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString::MyString(MyString&& other) noexcept
{
	moveFrom(std::move(other));
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

MyString::~MyString()
{
	free();
}

const char* MyString::c_str() const
{
	return data;
}

size_t MyString::getLenght() const
{
	return size;
}

size_t MyString::getCapacity() const
{
	return capacity;
}

MyString& MyString::operator+=(const MyString& other)
{
	if (getLenght() + other.getLenght() + 1 > capacity) {
		resize(nextPowerOfTwo(getLenght() + other.getLenght()));
	}


	std::strncat(data, other.data, other.getLenght());

	size = getLenght() + other.getLenght();
	return *this;
}

MyString& MyString::operator+=(char ch)
{
	if (size == capacity) {
		resize(nextPowerOfTwo(getLenght() * 2));
	}
	data[size++] = ch;
	data[size] = '\0';
	return *this;
}

char& MyString::operator[](size_t index)
{
	return data[index];
}

const char& MyString::operator[](size_t index) const
{
	return data[index];
}

std::ostream& operator<<(std::ostream& os, const MyString& obj)
{
	return os << obj.data;
}

std::istream& operator>>(std::istream& is, MyString& ref)
{
	char buff[1024];
	is >> buff;
	size_t buffStringSize = std::strlen(buff);

	if (buffStringSize > ref.getCapacity())
		ref.resize(nextPowerOfTwo(buffStringSize));

	strcpy(ref.data, buff);
	ref.size = buffStringSize;
	return is;

}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString res(lhs);
	res += rhs;
	return res;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}