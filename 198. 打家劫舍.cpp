class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        int n = nums.size();
        int first = nums[0];
        int second = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++)
        {
            int tmp = second;
            second = max(first + nums[i], second);
            first = tmp;
        }

        return second;
    }
};