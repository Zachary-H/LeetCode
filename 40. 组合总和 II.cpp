class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void backtrack(vector<int>& candidates, int target, int sum, int index, vector<bool>& sign)
    {
        if(sum == target)
        {
            res.push_back(path);
            return;
        }

        for(int i = index; i < candidates.size() && sum+candidates[i] <= target; i++)
        {
            if(i > 0 && candidates[i] == candidates[i-1] && sign[i-1] == false)
            {
                continue;
            }

            sum += candidates[i];
            path.push_back(candidates[i]);
            sign[i] = true;
            backtrack(candidates, target, sum, i+1, sign);
            sign[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<bool> sign(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0, sign);
        return res;
    }
};