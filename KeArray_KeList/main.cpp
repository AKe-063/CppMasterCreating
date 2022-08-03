#include <iostream>
#include "KeArray.h"
#include "KeList.h"

int main()
{
// 	auto arr = new KeArray<int>();
//   	arr->reserve(1);
//   	arr->push(1);
//   	arr->push(2);
//  	arr->insert(1, 3);
//  	arr->remove(2);
//  	arr->pop();
// 	arr->clear();
// 	int index = arr->findIndex(1);
// 
//     delete arr;
//     arr = nullptr;

	auto list1 = new KeList<int>();
 	auto node1 = list1->push(1);
	auto node2 = list1->push(2);
 	auto node3 = list1->insert(node2, 3);
 	auto ret = list1->find(2);
	list1->remove(node2);
 	list1->popAll();

	delete list1;
	list1 = nullptr;
	node1 = nullptr;
	node2 = nullptr;
	node3 = nullptr;
	return 0;
}