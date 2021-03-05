class Solution {
public:
    int myAtoi(string s) 
    {
        int i = 0;
        int flag = 1;
        long res = 0;

        while(s[i] == ' ') i++;
        if(s[i] == '-') flag = -1;
        if(s[i] == '-' || s[i] == '+') i++;

        for(; i < s.size() && isdigit(s[i]); i++)
        {
            res = res*10 + (s[i] - '0');
            if(res >= INT_MAX && flag == 1) return INT_MAX;
            if(res > INT_MAX && flag == -1) return INT_MIN;
        }

        return flag*res;
    }
};