class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) 
    {
        int n = T.size();
        vector<int> res(n, 0);
        stack<int> s;
        
        for(int i = 0; i < n; i++)
        {
            while(!s.empty() && T[i] > T[s.top()])
            {
                int tmp = s.top();
                s.pop();
                res[tmp] = i - tmp;
            }
            s.push(i);
        }

        return res;
    }
};