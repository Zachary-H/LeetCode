class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int number = nums[0];
        int times = 1;

        for(int i = 1; i < nums.size(); i++)
        {
            if(times == 0)
            {
                number = nums[i];
                times = 1;
            }

            else if(number == nums[i])
            {
                times++;
            }

            else
            {
                times--;
            }
        }

        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == number)
            {
                count++;
            }
        }

        if(count > (nums.size()/2))
        {
            return number;
        }
        else
        {
            return 0;
        }
    }
};