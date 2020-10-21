/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        
        ListNode* res = new ListNode(0);
        ListNode* tmp = res;

        while(l1 != nullptr && l2 != nullptr)
        {
            if(l1->val > l2->val)
            {
                tmp->next = l2;
                l2 = l2->next;
            }
            else
            {
                tmp->next = l1;
                l1 = l1->next;
            }

            tmp = tmp->next;
        }

        if(l1 == nullptr)
        {
            tmp->next = l2;
        }
        else if(l2 == nullptr)
        {
            tmp->next = l1;
        }

        return res->next;
    }
};