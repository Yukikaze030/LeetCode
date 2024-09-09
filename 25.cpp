struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        for(int i = 0;i<k;i++)
        {
            if(temp == nullptr)
                return head;
            temp = temp->next;
        }


    }

    ListNode* Switch(ListNode* head,ListNode* end)
    {
        if(head == end)
        {
            return head;
        }
        auto temp = Switch(head->next,end);
        head->next->next = head;
        head->next = nullptr;
        
        return temp;
    }
};