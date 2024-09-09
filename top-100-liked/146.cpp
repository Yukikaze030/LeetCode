#include <list>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

class Node
{
public:
    Node();
    Node(int t_key, int t_val)
    {
        key = t_key;
        val = t_val;
    }
    Node(int t_key, int t_val, Node *next, Node *last)
    {
        key = t_key;
        val = t_val;
        NextNode = next;
        LastNode = last;
    }

    int key = 0;
    int val = 0;
    Node *NextNode = nullptr;
    Node *LastNode = nullptr;
};

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        Maxsize = capacity;
    }

    int get(int key)
    {
        if (p_HeadNode == nullptr)
        {
            return -1;
        }
        else
        {
            auto it = m_map.find(key);
            if (it == m_map.end())
            {
                return -1;
            }
            else
            {
                auto pLast = it->second->LastNode;
                auto pNext = it->second->NextNode;
                if (pNext == nullptr)
                {
                }
                else if (pLast == nullptr)
                {
                    p_HeadNode = p_HeadNode->NextNode;
                    p_HeadNode->LastNode = nullptr;
                    it->second->LastNode = p_EndNode;
                    p_EndNode->NextNode = it->second;
                    p_EndNode = it->second;
                    p_EndNode->NextNode = nullptr;
                }
                else
                {
                    pLast->NextNode = pNext;
                    pNext->LastNode = pLast;
                    it->second->LastNode = p_EndNode;
                    p_EndNode->NextNode = it->second;
                    p_EndNode = it->second;
                    p_EndNode->NextNode = nullptr;
                }
                return it->second->val;
            }
        }
    }

    void put(int key, int value)
    {
        auto it = m_map.find(key);
        if (it == m_map.end())
        {
            auto pNode = new Node(key, value, nullptr, p_EndNode);
            m_map.insert(make_pair(key, pNode));
            size++;
            if (size > Maxsize)
            {
                auto pTemp = p_HeadNode;
                p_HeadNode = p_HeadNode->NextNode;
                int k = pTemp->key;
                m_map.erase(k);
                size--;
                delete pTemp;
            }

            if (p_EndNode == nullptr || p_HeadNode == nullptr)
            {
                p_EndNode = pNode;
                p_HeadNode = pNode;
            }
            else
            {
                p_EndNode->NextNode = pNode;
                p_EndNode = pNode;
            }
            p_HeadNode->LastNode = nullptr;
            p_EndNode->NextNode = nullptr;
        }
        else
        {
            it->second->val = value;
            auto pLast = it->second->LastNode;
            auto pNext = it->second->NextNode;
            if (pNext == nullptr)
            {
            }
            else if (pLast == nullptr)
            {
                p_HeadNode = p_HeadNode->NextNode;
                p_HeadNode->LastNode = nullptr;
                it->second->LastNode = p_EndNode;
                p_EndNode->NextNode = it->second;
                p_EndNode = it->second;
                p_EndNode->NextNode = nullptr;
            }
            else
            {
                pLast->NextNode = pNext;
                pNext->LastNode = pLast;
                it->second->LastNode = p_EndNode;
                p_EndNode->NextNode = it->second;
                p_EndNode = it->second;
                p_EndNode->NextNode = nullptr;
            }
        }
    }

    Node *p_HeadNode = nullptr;
    Node *p_EndNode = nullptr;
    int Maxsize = 0;
    map<int, Node *> m_map;
    int size = 0;
};

int main()
{
    // LRUCache lRUCache(2);
    // lRUCache.put(1, 1); // 缓存是 {1=1}
    // lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    // lRUCache.get(1);    // 返回 1
    // lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    // lRUCache.get(2);    // 返回 -1 (未找到)
    // lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    // lRUCache.get(1);    // 返回 -1 (未找到)
    // lRUCache.get(3);    // 返回 3
    // lRUCache.get(4);    // 返回 4

    LRUCache lRUCache(1);
    lRUCache.put(2, 1);
    // lRUCache.put(3, 2);
    // lRUCache.get(3);
    lRUCache.get(2);
    lRUCache.put(3, 2);
    lRUCache.get(2);
    lRUCache.get(3);
    // lRUCache.get(4);
}