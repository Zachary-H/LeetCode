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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* front = head;
        ListNode* latter = head;

        for(int i = 0; i < k; i++)
        {
            front = front->next;
        }

        while(front != nullptr)
        {
            front = front->next;;
            latter = latter->next;
        }

        return latter;
    }
};