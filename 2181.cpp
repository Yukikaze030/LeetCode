/**
 * Definition for singly-linked list.
 *
 */
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
    ListNode *mergeNodes(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        if(head->next->)
        int temp = head->val;
        auto p = mergeNodes(head->next);
        head->val = 
    }
};

int main()
{
    //[0,3,1,0,4,5,2,0]
    Solution S;
    ListNode S1(0);
    ListNode S2(2, &S1);
    ListNode S3(5, &S2);
    ListNode S4(4, &S3);
    ListNode S5(0, &S4);
    ListNode S6(1, &S5);
    ListNode S7(3, &S6);
    ListNode S8(0, &S7);
    auto p = S.mergeNodes(&S8);
}