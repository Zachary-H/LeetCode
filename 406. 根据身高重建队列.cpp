class Solution {
public:
    static bool cmp(const vector<int> a, const vector<int> b)
    {
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        sort(people.begin(), people.end(), cmp);
        list<vector<int>> l;
        for(const vector<int>& tmp : people)
        {
            int index = tmp[1];
            std::list<vector<int>>::iterator it = l.begin();
            while(index--) it++;
            l.insert(it, tmp);
        }
        return vector<vector<int>> (l.begin(), l.end());
    }
};