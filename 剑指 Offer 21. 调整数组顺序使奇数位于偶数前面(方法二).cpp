class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        vector<int> ans(len, 0);

        for(int i = 0; i < len; i++)
        {
            int val = nums[i];
            if(val & 1) ans[left++] = val;
            else ans[right--] = val;
        }

        return ans;
    }
};