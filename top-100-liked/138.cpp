
/*
// Definition for a Node.
*/
#include <map>
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return head;
        Node *p = new Node(head->val);
        m_map_2.insert({head, size});
        m_map_1.insert({size++, p});

        p->next = copyRandomList(head->next);
        if (head->random != nullptr)
        {
            auto it = m_map_2.find(head->random);
            p->random = m_map_1.find(it->second)->second;
        }
        else
        {
            p->random = nullptr;
        }
        return p;
    }

private:
    std::map<int, Node *>
        m_map_1;
    std::map<Node *, int> m_map_2;
    int size = 0;
};