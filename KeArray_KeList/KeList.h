#pragma once
#include <iostream>

template<class T>
struct KeNode
{
public:
	T value;
	KeNode* prev;
	KeNode* next;

	KeNode() {};
	KeNode(const T& value, const KeNode* prev, const KeNode* next)
	{
		this->value = value;
		this->prev = prev;
		this->next = next;
	}
};

template<class T>
class KeList
{
public:
	KeList();
	~KeList();

	T* push(const T& data);
	T* insert(const T* node, const T& data);
	T* find(const T& data);
	void remove(const T* node);
	void popAll();

	template<class T> friend std::ostream& operator<<(std::ostream& os, const KeList<T>& keList);

private:
	KeNode<T>* headPtr;
	size_t dataSize = 0;
	size_t memorySize = 0;
};

template<class T>
void KeList<T>::popAll()
{

}

template<class T>
void KeList<T>::remove(const T* node)
{

}

template<class T>
T* KeList<T>::find(const T& data)
{
	return nullptr;
}

template<class T>
T* KeList<T>::insert(const T* node, const T& data)
{
	return nullptr;
}

template<class T>
T* KeList<T>::push(const T& data)
{
	return nullptr;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const KeList<T>& keList)
{
	

	return os;
}

template<class T>
KeList<T>::KeList()
{
	
}

template<class T>
KeList<T>::~KeList()
{
	KeNode<T>* tempCurrentNodePtr;
	KeNode<T>* tempNextNodePtr = headPtr->next;
	while (tempNextNodePtr != headPtr)
	{
		tempCurrentNodePtr = tempNextNodePtr;
		tempNextNodePtr = tempNextNodePtr->next;
		delete tempCurrentNodePtr;
	}

	delete headPtr;
	headPtr = nullptr;
}