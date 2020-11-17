class Solution {
public:
    static bool cmp(int x, int y)
    {
        string sx = to_string(x);
        string sy = to_string(y);

        string A = sx + sy;
        string B = sy + sx;

        return A < B;
    }

    string minNumber(vector<int>& nums) 
    {
        if(nums.size() == 0) return "";
        if(nums.size() == 1) return to_string(nums[0]);

        string res;
        sort(nums.begin(), nums.end(), cmp);
        for(int i : nums)
        {
            res += to_string(i);
        }

        return res;
    }
};