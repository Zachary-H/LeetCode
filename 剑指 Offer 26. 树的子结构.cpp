/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSame(TreeNode* C, TreeNode* D)
    {
        if(D == nullptr) return true;

        if(C == nullptr) return false;

        if(C->val != D->val) return false;
        
        return isSame(C->left, D->left) && isSame(C->right, D->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == nullptr || B == nullptr) return false;

        bool res = false;

        if(A->val == B->val)
        {
            res = isSame(A, B);
        }

        if(!res)
        {
            res = isSubStructure(A->left, B);
        }

        if(!res)
        {
            res = isSubStructure(A->right, B);
        }

        return res;
    }
};