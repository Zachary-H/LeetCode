/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        ListNode dummyHead(0);
        dummyHead.next = head;
        ListNode* p = head;
        int len = 0;
        while(p)
        {
            len++;
            p = p->next;
        }

        for(int size = 1; size < len; size <<= 1)
        {
            ListNode* cur = dummyHead.next;
            ListNode* tail = &dummyHead;

            while(cur)
            {
                ListNode* left = cur;
                ListNode* right = cut(left, size);
                cur = cut(right, size);

                tail->next = merge(left, right);
                while(tail->next)
                {
                    tail = tail->next;
                }
            }
        }

        return dummyHead.next;
    }

    ListNode* cut(ListNode* head, int n)
    {
        ListNode* p = head;
        while(--n && p)
        {
            p = p->next;
        }

        if(!p) return nullptr;

        ListNode* next = p->next;
        p->next = nullptr;
        return next;
    }

    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode dummyHead(0);
        ListNode* p = &dummyHead;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                p->next = l1;
                p = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }

        p->next = l1 ? l1 : l2;
        return dummyHead.next;
    }
};