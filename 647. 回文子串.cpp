class Solution {
public:
    int extend(string& str, int i, int j, int n)
    {
        int tmp = 0;
        while(i >= 0 && j < n && str[i] == str[j])
        {
            i--;
            j++;
            tmp++;
        }
        return tmp;
    }
    
    int countSubstrings(string s) 
    {
        int res = 0;

        for(int i = 0; i < s.size(); i++)
        {
            res += extend(s, i, i, s.size());
            res += extend(s, i, i+1, s.size());
        }

        return res;
    }
};