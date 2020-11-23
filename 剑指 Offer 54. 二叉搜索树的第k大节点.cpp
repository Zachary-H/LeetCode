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
    int kthLargest(TreeNode* root, int k) {
        if(root == nullptr) return 0;
        stack<TreeNode*> st;
        TreeNode* node = root;

        do
        {
            while(node != nullptr)
            {
                st.push(node);
                node = node->right;
            }

            if(!st.empty())
            {
                node = st.top();
                st.pop();
                k--;
                if(k == 0)
                {
                    return node->val;
                }
            }

            node = node->left;
        }while(node != nullptr || !st.empty());

        return 0;
    }
};