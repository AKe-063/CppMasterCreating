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
	KeNode(const T& value, KeNode* const prev, KeNode* const next)
	{
		this->value = value;
		this->prev = prev;
		this->next = next;
	}
	template<class T> friend std::ostream& operator<<(std::ostream& os, const KeNode<T>& keNode)
	{
		os << keNode.value << std::endl;
		return os;
	}
};

template<class T>
class KeList
{
public:
	KeList();
	~KeList();

	KeNode<T>* push(const T& data);
	KeNode<T>* insert(KeNode<T>* const  node, const T& data);
	KeNode<T>* find(const T& data);
	void remove(KeNode<T>* const node);
	void popAll();

	template<class T> friend std::ostream& operator<<(std::ostream& os, const KeList<T>& keList);

protected:
	bool findNode(KeNode<T>* const node);

private:
	KeNode<T>* headPtr;
	size_t dataSize = 0;
	size_t memorySize = 0;
};

template<class T>
bool KeList<T>::findNode(KeNode<T>* const node)
{
	KeNode<T>* tempNodePtr = headPtr->next;
	while (tempNodePtr != headPtr)
	{
		if (tempNodePtr = node)
		{
			return true;
		}
		tempNodePtr = tempNodePtr->next;
	}
	return false;
}

template<class T>
KeNode<T>* KeList<T>::insert(KeNode<T>* const node, const T& data)
{
	KeNode<T>* tempNodePtr = headPtr->next;

	if (findNode(node))
	{
		KeNode<T>* newNodePtr = new KeNode<T>(data, headPtr->prev, node);
		node->prev->next = newNodePtr;
		node->prev = newNodePtr;
		return newNodePtr;
	}
	else
	{
		throw("Node is invalid.");
	}
}

template<class T>
void KeList<T>::popAll()
{
	KeNode<T>* tempCurrentNodePtr;
	KeNode<T>* tempNextNodePtr = headPtr->next;
	while (tempNextNodePtr != headPtr)
	{
		tempCurrentNodePtr = tempNextNodePtr;
		tempNextNodePtr = tempNextNodePtr->next;
		delete tempCurrentNodePtr;
	}

	headPtr->next = headPtr->prev = headPtr;
}

template<class T>
void KeList<T>::remove(KeNode<T>* const node)
{
	KeNode<T>* tempNodePtr = node;
	if (findNode(node))
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		delete tempNodePtr;
		tempNodePtr = nullptr;
	}
}

template<class T>
KeNode<T>* KeList<T>::find(const T& data)
{
	KeNode<T>* tempNodePtr = headPtr->next;
	while (tempNodePtr != headPtr)
	{
		if (tempNodePtr->value == data)
		{
			return tempNodePtr;
		}
		tempNodePtr = tempNodePtr->next;
	}

	return nullptr;
}

template<class T>
KeNode<T>* KeList<T>::push(const T& data)
{
	KeNode<T>* tempNode = new KeNode<T>(data, headPtr->prev, headPtr);
	headPtr->prev->next = tempNode;
	headPtr->prev = tempNode;

	return tempNode;
}

template<class T>
std::ostream& operator<< (std::ostream& os, const KeList<T>& keList)
{
	KeNode<T>* tempPtr = keList.headPtr->next;
	while (tempPtr != keList.headPtr)
	{
		os << tempPtr->value << std::endl;
		tempPtr = tempPtr->next;
	}

	return os;
}

template<class T>
KeList<T>::KeList()
{
	headPtr = new KeNode<T>();
	headPtr->prev = headPtr->next = headPtr;
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