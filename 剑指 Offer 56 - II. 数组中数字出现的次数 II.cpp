class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto i : nums) m[i]++;
        int res = 0;
        for(auto j : m)
        {
            if(j.second == 1)
            {
                res = j.first;
                break;
            }
        }
        return res;
    }
};