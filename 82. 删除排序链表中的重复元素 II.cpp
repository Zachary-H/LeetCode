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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;

        ListNode* pHead = new ListNode(0);
        pHead->next = head;
        ListNode* pre = pHead;
        ListNode* last = pre->next;

        while(last != nullptr)
        {
            while(last->next != nullptr && last->val != last->next->val)
            {
                pre = last;
                last = last->next;
            }

            while(last->next != nullptr && last->val == last->next->val)
            {
                last = last->next;
            }

            if(pre->next != last)
            {
                pre->next = last->next;
            }
            last = last->next;
        }

        return pHead->next;
    }
};