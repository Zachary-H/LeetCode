class Solution {
public:
    vector<int> partitionLabels(string S) 
    {
        int count[26];
        for(int i = 0; i < S.size(); i++)
        {
            count[S[i] - 'a'] = i;
        }

        int left = 0;
        int right = 0;
        vector<int> res;
        for(int i = 0; i < S.size(); i++)
        {
            right = max(right, count[S[i] - 'a']);
            if(i == right)
            {
                res.push_back(right - left + 1);
                left = i + 1;
            }
        }

        return res;
    }
};