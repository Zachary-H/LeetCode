class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;

        for(; i < nums.size() && nums[i] != target; i++);
        for(; j >= 0 && nums[j] != target; j--);

        return j-i+1 > 0 ? j-i+1 : 0;
    }
};