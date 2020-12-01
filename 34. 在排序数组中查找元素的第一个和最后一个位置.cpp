class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if(nums.size() == 0) return res;
        
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left <= right)
        {
            int mid = (left + right)/2;
            if(target < nums[mid])
            {
                right = mid - 1;
            }

            else if(target > nums[mid])
            {
                left = mid + 1;
            }

            else
            {
                int i = mid;
                for(; i >= 0; i--)
                {
                    if(nums[i] != target)
                    {
                        break;
                    }
                }
                res[0] = i + 1;

                int j = mid;
                for(; j < n; j++)
                {
                    if(nums[j] != target)
                    {
                        break;
                    }
                }
                res[1] = j - 1;
                break;
            }
        }

        return res;
    }
};