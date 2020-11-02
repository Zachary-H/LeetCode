class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void backtrack(vector<int>& candidates, int target, int sum, int index)
    {
        if(sum > target) return;
        if(sum == target)
        {
            res.push_back(path);
            return;
        }

        for(int i = index; i < candidates.size() && sum+candidates[i] <= target; i++)
        {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtrack(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0);
        return res;
    }
};