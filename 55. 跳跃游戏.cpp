class Solution {
public:
    bool canJump(vector<int>& nums) {
        int count = 0;
        if(nums.size() == 1) return true;

        for(int i = 0; i <= count; i++)
        {
            count = max(i+nums[i], count);
            if(count >= nums.size()-1) return true;
        }

        return false;
    }
};