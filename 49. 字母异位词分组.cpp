class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> mp;
        for(string str : strs)
        {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(str);
        }

        vector<vector<string>> res;
        for(auto it : mp)
        {
            res.push_back(it.second);
        }

        return res;
    }
};