class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto i : nums) m[i]++;

        priority_queue<pair<int,int>> que;
        for(auto i : m)
        {
            que.push({i.second,i.first});
        }

        vector<int> res;
        for(int i = 0; i < k; i++)
        {
            res.push_back(que.top().second);
            que.pop();
        }

        return res;
    }
};