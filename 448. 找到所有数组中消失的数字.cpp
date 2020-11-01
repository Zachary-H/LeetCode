class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int index = (nums[i]-1) % n;
            nums[index] += n;
        }

        for(int i = 0; i < n; i++)
        {
            if(nums[i] <= n) res.push_back(i+1);
        }

        return res;
    }
};