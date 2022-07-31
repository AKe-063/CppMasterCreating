#pragma once
#include <iostream>

template<class T> 
class KeArray
{
public:
	KeArray();
	~KeArray();

	//Change the memory space.
	void reserve(const int& num);
	//Add an element at the end of elements.
	void push(const T& data);
	//Insert data before the index.
	void insert(const int& index, const T& data);
	//Clear the element at the index.
	void remove(const int& index);
	//Clear an element at the end.
	void pop();
	//Clear all elements of the container.
	void clear();
	//Return an index of the element.
	T findIndex(const int& data);

	template<class T>friend std::ostream& operator<<(std::ostream& os, const KeArray<T>& keArray);

private:
	T* datas;
	size_t momerySize;
	size_t dataSize;
};

template<class T>
void KeArray<T>::pop()
{

}

template<class T>
void KeArray<T>::clear()
{

}

template<class T>
T KeArray<T>::findIndex(const int& data)
{

}

template<class T>
void KeArray<T>::remove(const int& index)
{

}

template<class T>
void KeArray<T>::insert(const int& index, const T& data)
{

}

template<class T>
KeArray<T>::KeArray()
{
	datas = nullptr;
	momerySize = 0;
	dataSize = 0;
}

template<class T>
KeArray<T>::~KeArray()
{
	delete datas;
	datas = nullptr;
	momerySize = 0;
	dataSize = 0;
}

template<class T>
void KeArray<T>::reserve(const int& num)
{
	if (num > (int)momerySize)
	{
		momerySize = num;
		datas = new T[momerySize];
	}
}

template<class T>
void KeArray<T>::push(const T& num)
{

}

template<class T>
std::ostream& operator<<(std::ostream& os, const KeArray<T>& keArray)
{
	for (size_t i = 0; i < keArray.momerySize; i++)
	{
		os << keArray.datas[i] << std::endl;
	}
	return os;
}