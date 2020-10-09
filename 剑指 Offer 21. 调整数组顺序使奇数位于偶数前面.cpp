class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        int tmp = 0;

        while(i < j)
        {
            while(i < j && (nums[i]&1) != 0) i++;
            while(i < j && (nums[j]&1) == 0) j--;

            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }

        return nums;
    }
};