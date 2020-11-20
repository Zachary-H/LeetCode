class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> res(2);

        int tmp = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            tmp ^= nums[i];
        }

        int flag = 1;
        int length = sizeof(int)*8;
        for(int i = 0; i < length; i++)
        {
            if(((flag<<i) & tmp) != 0)
            {
                flag <<= i;
                break;
            }
        }

        res[0] = 0;
        res[1] = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if((nums[i] & flag) == 0)
            {
                res[0] ^= nums[i];
            }
            else
            {
                res[1] ^= nums[i];
            }
        }

        return res;
    }
};