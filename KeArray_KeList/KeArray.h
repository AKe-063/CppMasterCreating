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
	int findIndex(const T& data);

	template<class T>friend std::ostream& operator<<(std::ostream& os, const KeArray<T>& keArray);

private:
	T* datas;
	size_t memorySize;
	size_t dataSize;
};

template<class T>
void KeArray<T>::pop()
{
	if (dataSize <= 0)
	{
		throw("Empty container.");
	}
	else
	{
		dataSize--;
	}
}

template<class T>
void KeArray<T>::clear()
{
	dataSize = 0;
}

template<class T>
int KeArray<T>::findIndex(const T& data)
{
	for (size_t i = 0; i < dataSize; i++)
	{
		if (datas[i] == data)
		{
			return (int)i;
		}
	}

	return -1;
}

template<class T>
void KeArray<T>::remove(const int& index)
{
	if (index + 1 > (int)dataSize)
	{
		throw("Index out of bounds.");
	}
	else if (index + 1 == dataSize)
	{
		dataSize--;
	}
	else
	{
		T* tempDatas = new T[dataSize - index - 1];
		for (size_t i = 0; i < dataSize - index - 1; i++)
		{
			tempDatas[i] = datas[index + i];
		}
		dataSize--;
		for (size_t i = index; i < dataSize; i++)
		{
			datas[i] = tempDatas[i - index];
		}
		delete[] tempDatas;
		tempDatas = nullptr;
	}
}

template<class T>
void KeArray<T>::insert(const int& index, const T& data)
{
	if (dataSize == memorySize)
	{
		if (memorySize == 0)
		{
			reserve(index + 1);
			datas[index] = data;
			dataSize = index;
		}
		else			//Memory full;
		{
			reserve(memorySize * 2);
			T* tempDatas = new T[dataSize - index];
			for (size_t i = 0; i < dataSize - index; i++)
			{
				tempDatas[i] = datas[index + i];
			}
			datas[index] = data;
			dataSize++;
			for (size_t i = index + 1; i < dataSize; i++)
			{
				datas[i] = tempDatas[i - index - 1];
			}
			delete[] tempDatas;
			tempDatas = nullptr;
		}
	}
	else		//DataSize < MemorySize
	{
		T* tempDatas = new T[dataSize - index];
		for (size_t i = 0; i < dataSize - index; i++)
		{
			tempDatas[i] = datas[index + i];
		}
		datas[index] = data;
		dataSize++;
		for (size_t i = index + 1; i < dataSize; i++)
		{
			datas[i] = tempDatas[i - index - 1];
		}
	}
}

template<class T>
KeArray<T>::KeArray()
{
	datas = nullptr;
	memorySize = 0;
	dataSize = 0;
}

template<class T>
KeArray<T>::~KeArray()
{
	delete datas;
	datas = nullptr;
	memorySize = 0;
	dataSize = 0;
}

template<class T>
void KeArray<T>::reserve(const int& num)
{
	if (num > (int)memorySize)
	{
		memorySize = num;
		T* tempDatas = datas;
		datas = new T[memorySize];
		for (size_t i = 0; i < dataSize; i++)
		{
			datas[i] = tempDatas[i];
		}
		delete tempDatas;
		tempDatas = nullptr;
	}
}

template<class T>
void KeArray<T>::push(const T& num)
{
	if (memorySize <= 0)
	{
		datas = new T[1];
		memorySize = 1;
		datas[dataSize] = num;
		dataSize++;
	}
	else if(memorySize > dataSize)
	{
		datas[dataSize] = num;
		dataSize++;
	}
	else
	{
		reserve(memorySize * 2);
		datas[dataSize] = num;
		dataSize++;
	}
}

template<class T>
std::ostream& operator<<(std::ostream& os, const KeArray<T>& keArray)
{
	for (size_t i = 0; i < keArray.dataSize; i++)
	{
		os << keArray.datas[i] << std::endl;
	}
	return os;
}