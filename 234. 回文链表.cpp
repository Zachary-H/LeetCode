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
    ListNode* Reverse(ListNode* head)
    {
        ListNode* tmp = nullptr;
        ListNode* cur = head;
        ListNode* pre = nullptr;

        while(cur)
        {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        return pre;
    }

    bool isPalindrome(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr) return true;

        ListNode* pre = head;
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;

        ListNode* cur1 = head;
        ListNode* cur2 = Reverse(slow);

        while(cur1)
        {
            if(cur1->val != cur2->val) return false;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        return true;
    }
};