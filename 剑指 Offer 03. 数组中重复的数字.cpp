class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> s;
        for(int i : nums)
        {
            if(s.count(i) != 0) return i;

            else 
            {
                s.insert(i);
            }
        }

        return -1;
    }
};