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
    bool Compare(TreeNode* left, TreeNode* right)
    {
        if(left == NULL && right != NULL) return false;
        else if(left != NULL && right == NULL) return false;
        else if(left == NULL && right == NULL) return true;
        else if(left->val != right->val) return false;

        bool outside = Compare(left->left, right->right);
        bool inside = Compare(left->right, right->left);
        bool res = outside && inside;
        return res;
    }

    bool isSymmetric(TreeNode* root) 
    {
        if(root == NULL) return true;
        return Compare(root->left, root->right);
    }
};