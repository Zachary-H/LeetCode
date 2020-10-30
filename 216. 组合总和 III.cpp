class Solution {
private:
    vector<vector<int>> res;
    vector<int> tmp;
public:
    void backtrack(int k, int target, int sum, int index)
    {
        if(sum > target)
        {
            return;
        }
        if(tmp.size() == k)
        {
            if(sum == target) res.push_back(tmp);
            return;
        }

        for(int i = index; i <= 9; i++)
        {
            tmp.push_back(i);
            sum += i;
            backtrack(k, target, sum, i+1);
            sum -= i;
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) 
    {
        backtrack(k, n, 0, 1);
        return res;
    }
};