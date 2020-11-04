class Solution {
private:
    vector<vector<string>> res;
    vector<string> path;
public:
    bool isPalindrome(string& str, int start, int end)
    {
        for(int i = start, j = end; i < j; i++, j--)
        {
            if(str[i] != str[j]) return false;
        }
        return true;
    }

    void backtrack(string& s, int index)
    {
        if(index >= s.size())
        {
            res.push_back(path);
            return;
        }

        for(int i = index; i < s.size(); i++)
        {
            if(isPalindrome(s, index, i))
            {
                string str = s.substr(index, i-index+1);
                path.push_back(str);
            }
            else 
            {
                continue; 
            }

            backtrack(s, i+1);
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) 
    {
        backtrack(s, 0);
        return res;
    }
};