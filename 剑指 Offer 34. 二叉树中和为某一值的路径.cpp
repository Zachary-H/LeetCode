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
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void backtrack(TreeNode* root, int sum)
    {
        if(root == nullptr) return;

        path.push_back(root->val);
        sum -= root->val;

        if(root->left == nullptr && root->right == nullptr && sum == 0)
        {
            res.push_back(path);
        }

        backtrack(root->left, sum);
        backtrack(root->right, sum);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        backtrack(root, sum);
        return res;
    }
};