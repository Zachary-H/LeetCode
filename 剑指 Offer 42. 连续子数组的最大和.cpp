class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int total = nums[0];
        int res = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            if(total >= 0)
            {
                total += nums[i];
            }
            else
            {
                total = nums[i];
            }

            res = max(total, res);
        }

        return res;
    }
};