class Solution {
public:
    bool Find(vector<string>& wordDict, string s)
    {
        for(auto i : wordDict)
        {
            if(i == s) return true;
        }

        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty() || wordDict.empty()) return false;

        vector<bool> res(s.size() + 1, false);
        res[0] = true;

        for(int i = 1; i <= s.size(); i++)
        {
            for(int j = i-1; j >= 0; j--)
            {
                if(res[j] && Find(wordDict, s.substr(j, i-j)))
                {
                    res[i] = true;
                    break;
                }
            }
        }

        return res[s.size()];
    }
};