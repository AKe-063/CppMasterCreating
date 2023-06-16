#include <iostream>
#include "KeArray.h"
#include "KeList.h"

int main()
{
    // KeArray<int>* arr = new KeArray<int>();
    // arr->reserve(1);
    // std::cout << *arr;
    // arr->push(1);
    // std::cout << *arr;
    // arr->push(2);
    // std::cout << *arr;
    // arr->insert(1, 3);
    // std::cout << *arr;
    // int index = arr->findIndex(3);
    // std::cout << index << std::endl;
    // arr->remove(2);
    // std::cout << *arr;
    // arr->pop();
    // std::cout << *arr;
    // arr->clear();
    // std::cout << *arr;
    // index = arr->findIndex(1);
    // std::cout << index;
    //
    //
    // delete arr;
    // arr = nullptr;

    auto list1 = new KeList<int>();
    auto node1 = list1->push(1);
    std::cout << *node1;
    auto node2 = list1->push(2);
    std::cout << *node2;
    auto node3 = list1->insert(node2, 3);
    std::cout << *node3;
    std::cout << *list1;
    auto ret = list1->find(2);
    std::cout << *ret;
    list1->remove(node2);
    std::cout << *list1;
    list1->popAll();
    std::cout << *list1;

    delete list1;
    list1 = nullptr;
    node1 = nullptr;
    node2 = nullptr;
    node3 = nullptr;
    return 0;
}

// template<class T>
// class TestTemp {
// public:
//     TestTemp(T value) : m_value(value) {}
//
//     friend std::ostream& operator<<(std::ostream& os, const TestTemp<T>& obj){
//         os << "MyTemplate: " << obj.m_value;
//         return os;
//     }
//
// private:
//     T m_value;
// };
//
// int main() {
//     TestTemp<int> a(123);
//     std::cout << a << std::endl; // 输出：MyTemplate: 123
//
//     TestTemp<std::string> b("hello");
//     std::cout << b << std::endl; // 输出：MyTemplate: hello
//
//     return 0;
// }
