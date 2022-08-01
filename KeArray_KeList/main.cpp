#include <iostream>
#include "KeArray.h"

int main()
{
	auto arr = new KeArray<int>();
  	arr->reserve(1);
  	arr->push(1);
  	arr->push(2);
 	arr->insert(1, 3);
 	arr->remove(2);
 	arr->pop();
	arr->clear();
	int index = arr->findIndex(1);

    delete arr;
    arr = nullptr;
	return 0;
}