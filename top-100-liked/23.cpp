#include <vector>
#include <algorithm>
using namespace std;
//  Definition for singly-linked list.
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *MinNode = nullptr;
        for (auto p_ListNode : lists)
        {
            if (p_ListNode == nullptr)
            {
                continue;
            }
            else if (MinNode == nullptr)
            {
                MinNode = p_ListNode;
            }
            else if (MinNode->val > p_ListNode->val)
            {
                MinNode = p_ListNode;
            }
        }

        if (MinNode == nullptr)
        {
            return nullptr;
        }
        else
        {
            auto p = find(lists.begin(), lists.end(), MinNode);
            *p = (*p)->next;
            MinNode->next = mergeKLists(lists);
            return MinNode;
        }
    }
};