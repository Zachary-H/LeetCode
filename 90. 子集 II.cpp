class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void backtrack(vector<int>& nums, int index, vector<bool>& used)
    {
        res.push_back(path);

        for(int i = index; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false)
            {
                continue;
            }

            path.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, i+1, used);
            used[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, used);
        return res;
    }
};