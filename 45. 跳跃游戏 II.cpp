class Solution {
public:
    int jump(vector<int>& nums) {
        int cur = 0;
        int next = 0;
        int res = 0;
        for(int i = 0; i < nums.size()-1; i++)
        {
            next = max(nums[i]+i, next);
            if(i == cur)
            {
                cur = next;
                res++;
            }
        }
        return res;
    }
};