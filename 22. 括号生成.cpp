class Solution {
public:
    void backtrack(vector<string>& res, string& path, int left, int right, int n)
    {
        if(path.size() == n*2)
        {
            res.push_back(path);
            return;
        }

        if(left < n)
        {
            path.push_back('(');
            backtrack(res, path, left+1, right, n);
            path.pop_back();
        }

        if(right < left)
        {
            path.push_back(')');
            backtrack(res, path, left, right+1, n);
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        string path = "";
        backtrack(res, path, 0, 0, n);

        return res;
    }
};