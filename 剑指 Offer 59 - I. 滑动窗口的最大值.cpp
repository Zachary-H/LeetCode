class Solution {
public:
    int Max(vector<int>& v)
    {
        int max = v[0];
        for(int i : v)
        {
            if(i > max)
            {
                max = i;
            }
        }
        return max;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int> res;

        if(nums.size() == 0) return res;

        for(int i = 0; i < nums.size()-k+1; i++)
        {
            vector<int> tmp;
            for(int j = i; j < i+k; j++)
            {
                tmp.push_back(nums[j]);
            }

            res.push_back(Max(tmp));
        }

        return res;
    }
};