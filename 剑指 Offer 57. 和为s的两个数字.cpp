class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        while(left < right)
        {
            int tmp = nums[left] + nums[right];
            if(tmp == target)
            {
                return vector<int> {nums[left], nums[right]};
            }
            else if(tmp > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        return vector<int> {-1, -1};
    }
};