#include <iostream>
#include "SkipList.hpp"
#include <cstdlib>
#include <ctime>

using namespace KSkipList;

void creatNode(SkipList *skipList)
{
    // 使用当前时间作为随机生成器种子
    std::srand(static_cast<unsigned int>(std::time(0)));

    for (auto i = 0; i < 200; i++)
        skipList->insert(new SLNode(std::rand() % 1000));
}

int main()
{
    auto skipList = new SkipList();
    creatNode(skipList);

    skipList->insert(new SLNode(61));
    skipList->display();
    auto result = skipList->search(61);
    std::cout << (result == nullptr ? -1 : result->data) << std::endl;

    skipList->remove(61);
    skipList->display();
    result = skipList->search(61);
    std::cout << (result == nullptr ? -1 : result->data) << std::endl;

    return 0;
}