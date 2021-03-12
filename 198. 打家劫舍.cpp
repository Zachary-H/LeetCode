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



//¶þË¢

class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }

        return dp[n-1];
    }
};