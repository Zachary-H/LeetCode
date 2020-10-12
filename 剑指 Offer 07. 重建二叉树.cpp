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
    TreeNode* build(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start, int in_end)
    {
        if(pre_start > pre_end || in_start > in_end)
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[pre_start]);
        for(auto i = in_start; i <= in_end; i++)
        {
            if(preorder[pre_start] == inorder[i])
            {
                root->left = build(preorder, pre_start+1, pre_start+i-in_start, inorder, in_start, i-1);
                root->right = build(preorder, pre_start+i-in_start+1, pre_end, inorder, i+1, in_end);
                break;
            }
        }
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty() || preorder.size() != inorder.size())
        {
            return nullptr;
        }

        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};