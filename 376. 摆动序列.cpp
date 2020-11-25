class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();

        int curdiff = 0;
        int prediff = 0;
        int res = 1;

        for(int i = 1; i < nums.size(); i++)
        {
            curdiff = nums[i] - nums[i-1];

            if((curdiff > 0 && prediff <= 0) || (prediff >= 0 && curdiff <0))
            {
                res++;
                prediff = curdiff;
            }
        }
        
        return res;
    }
};