class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp = nums;
        int n = dp.size();
        int ans = dp[0];

        for(int i = 1; i < n; i++)
        {
            if(dp[i-1] > 0) dp[i] = dp[i-1] + dp[i];

            ans = max(dp[i], ans);
        }

        return ans;
    }
};