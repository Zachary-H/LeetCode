class Solution {
private:
    vector<vector<int>> res;
    vector<int> tmp;
public:
    void backtrack(int n, int k, int index)
    {
        if(tmp.size() == k)
        {
            res.push_back(tmp);
            return;
        }

        for(int i = index; i <= n-(k-tmp.size())+1; i++)
        {
            tmp.push_back(i);
            backtrack(n, k, i+1);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) 
    {
        backtrack(n, k, 1);
        return res;
    }
};