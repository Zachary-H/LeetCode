class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;

        int low = 1;
        int high = 2;
        while(low < high)
        {
            int total = (low + high) * (high - low + 1) / 2;

            if(total == target)
            {
                vector<int> tmp;
                for(int i = low; i <= high; i++)
                {
                    tmp.push_back(i);
                }
                res.push_back(tmp);
                low++;
            }
            else if(total < target)
            {
                high++;
            }
            else
            {
                low++;
            }
        }

        return res;
    }
};