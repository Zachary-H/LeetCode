class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void backtrack(vector<int>& nums, vector<bool>& used)
    {
        if(path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false)
            {
                continue;
            }

            if(used[i] == false)
            {
                path.push_back(nums[i]);
                used[i] = true;
                backtrack(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtrack(nums, used);
        return res;
    }
};