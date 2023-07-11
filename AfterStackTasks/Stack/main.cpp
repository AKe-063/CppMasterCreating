#include <iostream>
#include <string>

#include "KStack.h"

void main()
{
    KStack<std::string>* stack = new KStack<std::string>(3);
    for (auto i = 0; i < 4; i++)
    {
        stack->push(std::to_string(i));
    }

    for (auto i = 0; i < 2; i++)
    {
        stack->pop();
    }

    delete stack;
}
