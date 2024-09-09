#include <map>
#include <vector>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        add(head);
        ListNode *head1 = *m_map.begin()->second.begin();
        ListNode *last = nullptr;
        ListNode *Now = nullptr;
        for (auto it : m_map)
        {
            for (auto it1 : it.second)
            {
                if (last == nullptr)
                {
                    last = it1;
                }
                else
                {
                    Now = it1;
                    last->next = Now;
                    last = Now;
                }
            }
        }

        last->ext = nullptr;
        return head1;
    }

    void add(ListNode *head)
    {
        if (head == nullptr)
        {
            return;
        }
        auto it = m_map.find(head->val);
        if (it == m_map.end())
        {
            std::vector<ListNode *> temp_vec;
            temp_vec.push_back(head);
            m_map.insert({head->val, temp_vec});
        }
        else
        {
            it->second.push_back(head);
        }
        add(head->next);
    }

    std::map<int, std::vector<ListNode *>> m_map;
};

int main()
{
    ListNode a4(3);
    ListNode a3(1, &a4);
    ListNode a2(2, &a3);
    ListNode a1(4, &a2);

    Solution S;
    ListNode *p = S.sortList(&a1);
}