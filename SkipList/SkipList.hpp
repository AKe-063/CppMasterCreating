#ifndef SkipList_H
#define SkipList_H
#include <iostream>
#include <vector>
#include <random>

namespace KSkipList
{
    struct SLNode
    {
        int data;
        SLNode *next = nullptr, *down = nullptr;

        SLNode(const int inData = 0) : data(inData) {}
        SLNode(const SLNode &inNode) : data(inNode.data), next(inNode.next), down(inNode.down) {}
    };

    class SkipList
    {
        int maxLevel;
        std::vector<SLNode *> headVec;

    public:
        SkipList(const int &inMaxLevel = 4) : maxLevel(inMaxLevel)
        {
            headVec.push_back(new SLNode());
            for (auto i = 1; i < inMaxLevel; i++)
            {
                headVec.push_back(new SLNode());
                headVec[i]->down = headVec[i - 1];
            }
        };

        void insert(SLNode *const node)
        {
            auto rebuildLevel = randomLevel();
            SLNode *upPtr = nullptr;
            for (auto level = rebuildLevel; level >= 0; level--)
            {
                auto tempNode = new SLNode(*node);
                auto iterPtr = headVec[level]->next;
                if (upPtr != nullptr)
                    upPtr->down = tempNode;
                upPtr = tempNode;

                // init list
                if (iterPtr == nullptr)
                {
                    headVec[level]->next = tempNode;
                    continue;
                }

                if (iterPtr->data >= tempNode->data)
                {
                    tempNode->next = headVec[level]->next;
                    headVec[level]->next = tempNode;
                    continue;
                }

                while (iterPtr != nullptr)
                {
                    if (iterPtr->next == nullptr || iterPtr->next->data >= tempNode->data)
                    {
                        tempNode->next = iterPtr->next;
                        iterPtr->next = tempNode;
                        break;
                    }

                    iterPtr = iterPtr->next;
                }
            }
        };

        SLNode *search(const int searchNum)
        {
            // find the first created list.
            SLNode *iter = nullptr;
            for (auto index = headVec.size() - 1; index >= 0; index--)
            {
                auto headPtr = headVec[index];
                if (headPtr->next == nullptr || headPtr->next->data > searchNum)
                    continue;
                iter = headPtr->next;
                break;
            }

            if (iter->data > searchNum)
                return nullptr;

            while (iter->data != searchNum)
            {
                if (iter->next == nullptr || iter->next->data > searchNum)
                {
                    if (iter->down != nullptr)
                    {
                        iter = iter->down;
                        continue;
                    }

                    return nullptr;
                }

                iter = iter->next;
            }

            return iter;
        }

        void remove(const int removeNum)
        {
            auto removeNode = this->search(removeNum);
            if (removeNode == nullptr)
                return;

            // find the first created list.
            SLNode *iter = nullptr;
            SLNode *headPtr = nullptr;
            for (auto index = headVec.size() - 1; index >= 0; index--)
            {
                headPtr = headVec[index];
                if (headPtr->next == nullptr || headPtr->next->data > removeNum)
                    continue;
                iter = headPtr->next;
                break;
            }

            auto prevPtr = headPtr;
            while (iter != nullptr)
            {
                if (iter->data != removeNum)
                {
                    prevPtr = iter->data > removeNum ? prevPtr->down : iter;
                    iter = prevPtr->next;
                    continue;
                }

                prevPtr->next = iter->next;
                iter->next = nullptr;
                iter->down = nullptr;
                delete iter;
                iter = prevPtr->down;
            }
        }

        void display()
        {
            for (auto &&headPtr : headVec)
            {
                auto iter = headPtr->next;
                while (iter != nullptr)
                {
                    std::cout << iter->data << "(" << (iter->down == nullptr ? 0 : iter->down->data) << ")"
                              << "\t";
                    iter = iter->next;
                }
                std::cout << std::endl;
            }
        }

    private:
        const int randomLevel()
        {
            std::random_device rd;                          // 将用于为随机数生成引擎获取种子
            std::mt19937 gen(rd());                         // 使用Mersenne Twister 19937生成器初始化标准 mersenne_twister_engine
            std::uniform_real_distribution<> dis(0.0, 1.0); // 创建均匀分布

            int level = 0;
            while (dis(gen) < 0.5 && level < maxLevel - 1)
                level += 1;
            return level;
        }
    };
}

#endif