class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int tmp = 0;
        for(int i : nums)
        {
            tmp ^= i;
        }

        int flag = 1;
        while((flag & tmp) == 0)
        {
            flag <<= 1;
        }

        int a = 0;
        int b = 0;
        for(int i : nums)
        {
            if((i & flag) == 0)
            {
                a ^= i;
            }
            else
            {
                b ^= i;
            }
        }

        return vector<int>{a,b};
    }
};