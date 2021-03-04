class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
    {
        vector<vector<int>> res;
        int min = INT_MAX;
        sort(arr.begin(), arr.end());

        for(int i = 0; i < arr.size()-1; ++i)
        {
            int j = i+1;
            if(arr[j] - arr[i] == min)
            {
                vector<int> tmp = {arr[i], arr[j]};
                res.push_back(tmp);
            }
            else if(arr[j] - arr[i] < min)
            {
                res = {{arr[i],arr[j]}};
                min = arr[j] - arr[i];
            }
        }

        return res;
    }
};