#include <iostream>

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;

        if (k <= 1)
        {
            return head;
        }
        for (int i = 0; i < k - 1; i++)
        {

            if (temp == nullptr)
                return head;
            temp = temp->next;
            if (temp == nullptr)
                return head;
        }
        ListNode *TempNext = temp->next;
        ListNode *pp = Switch(head, temp);
        pp->next = reverseKGroup(TempNext, k);
        return temp;
    }

    ListNode *Switch(ListNode *head, ListNode *end)
    {
        if (head == end)
        {
            p = head;
            return head;
        }
        auto temp = Switch(head->next, end);
        temp->next = head;
        head->next = nullptr;
        return head;
    }

    ListNode *p = nullptr;
};

int main()
{
    //[1,2,3,4,5] k=2;
    // ListNode a5(5);
    // ListNode a4(4, &a5);
    // ListNode a3(3, &a4);
    // ListNode a2(2, &a3);
    ListNode a2(2);
    ListNode a1(1, &a2);

    Solution S;
    ListNode *temp = S.reverseKGroup(&a1, 2);
}