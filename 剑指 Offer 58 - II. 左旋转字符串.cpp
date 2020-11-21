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

    string reverseLeftWords(string s, int n) 
    {
        if(s.empty() || n < 0) return s;

        int step = n % s.size();

        Reverse(s, 0, step-1);
        Reverse(s, step, s.size()-1);
        Reverse(s, 0, s.size()-1);

        return s;
    }
};