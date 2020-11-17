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
    int getLength(ListNode *head)
    {
        int len = 0;
        while(head != nullptr)
        {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(headA == nullptr || headB == nullptr) return nullptr;

        int l1 = getLength(headA);
        int l2 = getLength(headB);

        int step = abs(l1 - l2);
        if(l1 > l2)
        {
            while(step > 0)
            {
                headA = headA->next;
                step--;
            }
        }
        else
        {
            while(step > 0)
            {
                headB = headB->next;
                step--;
            }
        }

        while(headA != nullptr && headB != nullptr)
        {
            if(headA == headB)
            {
                return headA;
            }

            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;
    }
};