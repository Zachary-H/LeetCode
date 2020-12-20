class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        vector<int> count(26);
        vector<bool> used(26, false);
        string res = "";

        for(auto i : s)
        {
            count[i-'a']++;
        }

        for(auto i : s)
        {
            count[i-'a']--;
            if(used[i-'a']) continue;

            while(res.size() > 0 && i < res[res.size()-1] && count[res[res.size()-1]-'a'] > 0)
            {
                used[res[res.size()-1]-'a'] = false;
                res.erase(res.size()-1);
            }

            res += i;
            used[i-'a'] = true;
        }

        return res;
    }
};