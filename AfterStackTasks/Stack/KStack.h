#pragma once
#include <stdexcept>
#include <memory>

template <typename T>
class KStack
{
private:
    std::unique_ptr<T[]> elements;
    int capacity;
    int count;

    void increaseCapacity()
    {
        capacity *= 2;
        std::unique_ptr<T[]> newElements(new T[capacity]);
        for (int i = 0; i < count; ++i)
        {
            newElements[i] = elements[i];
        }
        elements.swap(newElements);

        std::cout << "decreaseCapacity to: " << capacity << ", current count: " << count;
    }

    void decreaseCapacity()
    {
        capacity /= 2;
        std::unique_ptr<T[]> newElements(new T[capacity]);
        for (int i = 0; i < count; ++i)
        {
            newElements[i] = elements[i];
        }
        elements.swap(newElements);

        std::cout << "decreaseCapacity to: " << capacity << ", current count: " << count;
    }

    void printElements()
    {
        for (auto index = 0; index < count; index++)
        {
            std::cout << elements[index] << " ";
        }
        std::cout << std::endl;
    }

public:
    KStack(const int initialCapacity = 10) : capacity(initialCapacity), count(0), elements(new T[initialCapacity])
    {
    }

    void push(T const& elem)
    {
        if (count == capacity) increaseCapacity();
        elements[count++] = elem;
        printElements();
    }

    void pop()
    {
        if (count == 0)
        {
            throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        --count;

        if (count <= capacity / 2) decreaseCapacity();
        printElements();
    }

    T top() const
    {
        if (count == 0)
        {
            throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return elements[count - 1];
    }
};
