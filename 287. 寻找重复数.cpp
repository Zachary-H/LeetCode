class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        while(true)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(fast == slow)
            {
                break;
            }
        }

        int finder = 0;
        while(true)
        {
            finder = nums[finder];
            slow = nums[slow];
            if(finder == slow)
            {
                break;
            }
        }

        return slow;
    }
};