class Solution {
public:
    void Reverse(string& s, int start, int end)
    {
        while(start < end)
        {
            char tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            start++;
            end--;
        }
    }

    void removeExtraSpaces(string& s) 
    {
        for (int i = s.size() - 1; i > 0; i--) 
        {
            if (s[i] == s[i - 1] && s[i] == ' ') 
            {
                s.erase(s.begin() + i);
            }
        }
        
        if (s.size() > 0 && s[s.size() - 1] == ' ') 
        {
            s.erase(s.begin() + s.size() - 1);
        }
        
        if (s.size() > 0 && s[0] == ' ') 
        {
            s.erase(s.begin());
        }
    }

    string reverseWords(string s) 
    {
        if(s.size() == 0) return s;
        removeExtraSpaces(s);

        int i = 0;
        int j = 0;
        int len = s.size();
        while(i < len)
        {
            while(i < len && !isspace(s[i])) i++;
            Reverse(s, j, i-1);
            while(i < len && isspace(s[i])) i++;
            j = i;
        }

        Reverse(s, j, i-1);
        Reverse(s, 0, i-1);

        return s;
    }
};