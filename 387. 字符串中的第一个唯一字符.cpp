class Solution {
public:
    int firstUniqChar(string s) 
    {
        vector<int> count(26, 0);
        for(int i = 0; i < s.size(); i++)
        {
            count[s[i] - 'a']++;
        }

        int res = -1;
        for(int i = 0; i < s.size(); i++)
        {
            if(count[s[i] - 'a'] == 1)
            {
                res = i;
                break;
            }
        }

        return res;
    }
};