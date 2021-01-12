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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = NULL;
        ListNode* pre = head;

        while(pre != NULL)
        {
            ListNode* tmp = pre->next;
            pre->next = cur;
            cur = pre;
            pre = tmp;
        }

        return cur;
    }
};