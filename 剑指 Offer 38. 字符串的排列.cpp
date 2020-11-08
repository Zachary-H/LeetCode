class Solution {
private:
    vector<string> res;
public:
    void swap(string& s, int i, int j)
    {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }

    bool judge(string& s, int start, int end)
    {
        for(int i = start; i < end; i++)
        {
            if(s[i] == s[end])
            {
                return true;
            }
        }

        return false;
    }

    void backtrack(string& s, int index)
    {
        if(index == s.size()-1)
        {
            res.push_back(s);
            return;
        }

        for(int i = index; i < s.size(); i++)
        {
            if(judge(s, index, i)) continue;
            swap(s, index, i);
            backtrack(s, index+1);
            swap(s, index, i);
        }
    }

    vector<string> permutation(string s) 
    {
        backtrack(s, 0);
        return res;
    }
};