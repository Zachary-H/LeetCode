class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void backtrack(vector<int>& nums, int index)
    {
        if(path.size() > 1)
        {
            res.push_back(path);
        }

        int used[201] = {0};
        //unordered_set<int> used;
        for(int i = index; i < nums.size(); i++)
        {
            if((!path.empty() && nums[i] < path.back()) || used[nums[i] + 100] == 1)   //used.find(nums[i]) != used.end()
            {
                continue;
            }

            used[nums[i] + 100] = 1;
            //used.insert(nums[i]);
            path.push_back(nums[i]);
            backtrack(nums, i+1);
            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        backtrack(nums, 0);
        return res;
    }
};