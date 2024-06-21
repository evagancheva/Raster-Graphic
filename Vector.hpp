#pragma once

template<typename  T>
class MyVector {
	T* data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void free();
	void resize(size_t cap);

	void copyFrom(const MyVector& other);
	void moveFrom(MyVector&& other);

	unsigned getNextPowerOfTwo(unsigned int n)
	{
		if (n == 0) return 1;

		while (n & (n - 1))
			n &= (n - 1);

		return n << 1;
	}
public:
	MyVector() = default;
	MyVector(const T* arr, size_t size);
	MyVector(size_t newSize);

	MyVector(const MyVector& other);
	MyVector(MyVector&& other);

	MyVector& operator=(const MyVector& other);
	MyVector& operator=(MyVector&& other);

	void push_bask(const T& el);
	void push_back(T&& el);
	void pop_back();

	size_t getSize()const;
	size_t getCap() const;

	void insert(const T& el, size_t index);
	void insert(T&& el, size_t index);

	void erase(size_t index);
	void clear();

	const T& operator[](size_t index) const;
	T& operator[](size_t index);

	bool isEmpty()const;
};

template<typename T>
void MyVector<T>::free()
{
	delete[]data;
	data = nullptr;
	size = capacity = 0;
}

template<typename T>
void MyVector<T>::resize(size_t cap)
{
	T* newData = new T[cap];
	for (size_t i = 0; i < getSize(); i++)
	{
		newData[i] = this->data[i];
	}

	delete[] this->data;
	this->data = newData;
	this->capacity = cap;
}

template<typename T>
void MyVector<T>::copyFrom(const MyVector<T>& other)
{
	size = other.size;
	capacity = other.capacity;

	data = new T[capacity];
	for (size_t i = 0; i < size; i++) {
		data[i] = other.data[i];
	}

}

template<typename T>
void MyVector<T>::moveFrom(MyVector<T>&& other)
{
	data = other.data;
	other.data = nullptr;

	capacity = other.capacity;
	other.capacity = 0;

	size = other.size;
	other.size = 0;
}

template<typename T>
MyVector<T>::MyVector(const T* arr, size_t size)
{
	capacity = getNextPowerOfTwo(size);
	this->size = size;

	data = new T[capacity];
	for (size_t i = 0; i < size; i++) {
		data[i] = arr[i];
	}
}

template<typename T>
MyVector<T>::MyVector(size_t newSize)
{
	this->capacity = getNextPowerOfTwo(newSize);
	this->data = new T[this->capacity];
	size = newSize;
}

template<typename T>
MyVector<T>::MyVector(const MyVector<T>& other)
{
	copyFrom(other);
}

template<typename T>
MyVector<T>::MyVector(MyVector<T>&& other)
{
	moveFrom(std::move(other));
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(MyVector<T>&& other)
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T>
void MyVector<T>::push_bask(const T& el)
{
	if (size >= capacity) {
		resize(capacity * 2);
	}

	data[size] = el;
	size++;
}

template<typename T>
void MyVector<T>::push_back(T&& el)
{
	if (size >= capacity) {
		resize(capacity * 2);
	}
	data[size] = el;
	size++;
}

template<typename T>
inline void MyVector<T>::pop_back()
{
	if (getSize() >= 0) {
		size--;
	}
	if ((getSize() * 4) <= getCap())
	{
		resize(getCap() / 2);
	}

}

template<typename T>
size_t MyVector<T>::getSize() const
{
	return size;
}

template<typename T>
size_t MyVector<T>::getCap() const
{
	return capacity;
}

template<typename T>
void MyVector<T>::insert(const T& el, size_t index)
{
	if (index >= getSize())
		return;

	data[index] = el;
}

template<typename T>
void MyVector<T>::insert(T&& el, size_t index)
{
	if (index >= getSize())
		return;

	data[index] = el;
}

template<typename T>
void MyVector<T>::erase(size_t index)
{
	if (index >= getSize() || getSize() <= 0) {
		return;
	}
	for (size_t i = index; i < getSize() - 1; i++)
	{
		this->data[i] = this->data[i + 1];
	}
	size--;
}

template<typename T>
void MyVector<T>::clear()
{
	for (int i = 0; i < getSize(); i++) {
		data[i] = T();
	}
}

template<typename T>
const T& MyVector<T>::operator[](size_t index) const
{
	return data[index];
}

template<typename T>
T& MyVector<T>::operator[](size_t index)
{
	return data[index];
}

template<typename T>
bool MyVector<T>::isEmpty() const
{
	return getSize() == 0;
}