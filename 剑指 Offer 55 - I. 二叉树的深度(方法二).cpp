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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;

        while(!q.empty())
        {
            int size = q.size();
            depth++;
            for(int i = 0; i < size; i++)
            {
                TreeNode *p = q.front();
                q.pop();
                if(p->left != nullptr) q.push(p->left);
                if(p->right != nullptr) q.push(p->right);
            }
        }

        return depth;
    }
};