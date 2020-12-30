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
    int maxd = 0;

    int diameterOfBinaryTree(TreeNode* root) 
    {
        depth(root);
        return maxd;
    }

    int depth(TreeNode* root)
    {
        if(root == nullptr) return 0;

        int r = depth(root->right);
        int l = depth(root->left);

        maxd = max(maxd, l + r);
        return max(l, r) + 1;
    }
};