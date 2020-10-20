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
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode* left = head;
        ListNode* mid = left->next;
        ListNode* right = mid->next;

        while(right != nullptr)
        {
            mid->next = left;
            left = mid;
            mid = right;
            right = right->next;
        }

        mid->next = left;
        head->next = nullptr;

        return mid;
    }
};