class Solution {
private:
    vector<string> res;
public:
    bool isVaild(string& s, int start, int end)
    {
        if(start > end)
        {
            return false;
        }

        if(s[start] == '0' && start != end)
        {
            return false;
        }

        int sum = 0;
        for(int i = start; i <= end; i++)
        {
            if(s[i] < '0' || s[i] > '9')
            {
                return false;
            }

            sum = sum*10 + (s[i]-'0');
            if(sum > 255)
            {
                return false;
            }
        }
        return true;
    }

    void backtrack(string& s, int index, int point)
    {
        if(point == 3)
        {
            if(isVaild(s, index, s.size()-1))
            {
                res.push_back(s);
            }
            return;
        }

        for(int i = index; i < s.size(); i++)
        {
            if(isVaild(s, index, i))
            {
                s.insert(s.begin() + i + 1, '.');
                point++;
                backtrack(s, i+2, point);
                point--;
                s.erase(s.begin() + i + 1);
            }
            else break;
        }
    }

    vector<string> restoreIpAddresses(string s) 
    {
        backtrack(s, 0, 0);
        return res;
    }
};