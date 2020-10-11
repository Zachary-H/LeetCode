class Solution {
public:
    string reverseWords(string s) {
        stack<string> sta;
        int i = 0;
        int j = 0;
        for(j = 0; j < s.size(); j++)
        {
            if(s[j] == ' ')
            {
                if(i < j)
                {
                    sta.push(s.substr(i, j-i));
                }
                i = j + 1;
            }
        }

        if(i < s.size())
        {
            sta.push(s.substr(i, j-i));
        }

        string res = "";
        while(!sta.empty())
        {
            res += sta.top() + " ";
            sta.pop();
        }
        return res.substr(0, res.size()-1);
    }
};