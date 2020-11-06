class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void backtrack(vector<int>& nums, int index)
    {
        res.push_back(path);
        if(index >= nums.size())
        {
            return;
        }

        for(int i = index; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtrack(nums, i+1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        backtrack(nums, 0);
        return res;
    }
};