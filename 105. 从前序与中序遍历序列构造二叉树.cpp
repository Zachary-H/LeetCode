/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    unordered_map<int, int> index;
public:
    TreeNode* build(const vector<int>& preorder, int preLeft, int preRight, const vector<int>& inorder, int inLeft, int inRight)
    {
        if(preLeft > preRight)
        {
            return nullptr;
        }

        int pre_root = preLeft;
        int in_root = index[preorder[pre_root]];

        TreeNode* root = new TreeNode(preorder[pre_root]);

        root->left = build(preorder, preLeft+1, in_root-inLeft+preLeft, inorder, inLeft, in_root-1);
        root->right = build(preorder, in_root-inLeft+preLeft+1, preRight, inorder, in_root+1, inRight);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int n = preorder.size();
        for(int i = 0; i < n; i++)
        {
            index[inorder[i]] = i;
        }

        return build(preorder, 0, n-1, inorder, 0, n-1);
    }
};