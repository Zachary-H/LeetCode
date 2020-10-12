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
    void Reverse(ListNode* head, vector<int>& res)
    {
        if(head == nullptr)
        {
            return;
        }

        Reverse(head->next, res);
        res.push_back(head->val);
    }

    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        Reverse(head, res);
        return res;
    }
};