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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(root == nullptr) return res;

        stack<TreeNode*> st;
        queue<TreeNode*> q;
        st.push(root);
        int flag = 1;
        vector<int> tmp;

        while(!st.empty())
        {
            int size = st.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* cur = st.top();
                st.pop();
                tmp.push_back(cur->val);
                TreeNode* first = (flag==1)?cur->left:cur->right;
                TreeNode* second = (flag==1)?cur->right:cur->left;
                if(first != nullptr) q.push(first);
                if(second != nullptr) q.push(second);
            }
            res.push_back(tmp);

            while(!q.empty())
            {
                st.push(q.front());
                q.pop();
            }

            flag = (flag==1)?2:1;
            tmp.clear();
        }

        return res;
    }
};