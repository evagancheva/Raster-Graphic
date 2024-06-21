#pragma once
#include<iostream>
class MyString
{
	char* data = nullptr;
	size_t capacity = 0;
	size_t size = 0;

	void free();
	void copyFrom(const MyString& other);
	void moveFrom(MyString&& other);
	void resize(size_t cap);

public:
	MyString() = default;
	MyString(const char* data);

	MyString(const MyString& other);
	MyString(MyString&& other)noexcept;

	MyString& operator=(const MyString& other);
	MyString& operator=(MyString&& other) noexcept;

	~MyString();

	const char* c_str()const;
	size_t getLenght()const;
	size_t getCapacity()const;

	MyString& operator+=(const MyString& other);
	MyString& operator+=(char ch);

	char& operator[](size_t index);
	const char& operator[](size_t index)const;

	friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
	friend std::istream& operator>>(std::istream& is, MyString& ref);
	friend MyString operator+(const MyString& lhs, const MyString& rhs);
};

bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);

