class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.empty() && popped.empty())
        {
            return true;
        }

        stack<int> st;
        int i = 0;
        int j = 0;
        for(; i < pushed.size(); i++)
        {
            st.push(pushed[i]);
            while(!st.empty() && st.top() == popped[j])
            {
                st.pop();
                j++;
            }
        }

        return st.empty();
    }
};