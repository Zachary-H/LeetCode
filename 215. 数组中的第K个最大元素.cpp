class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        if(nums.empty() || k < 1)
        {
            return INT_MIN;
        }

        int len = nums.size();
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for(int i = 0; i < k; i++)
        {
            min_heap.push(nums[i]);
        }

        for(int i = k; i < len; i++)
        {
            if(nums[i] >= min_heap.top())
            {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }

        return min_heap.top();
    }
};