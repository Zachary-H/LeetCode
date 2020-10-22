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
    vector<int> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* tmp = q.front();
            q.pop();
            res.push_back(tmp->val);
            if(tmp->left != nullptr)
            {
                q.push(tmp->left);
            }
            if(tmp->right != nullptr)
            {
                q.push(tmp->right);
            }
        }

        return res;
    }
};