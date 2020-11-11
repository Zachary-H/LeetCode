class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res(k, 0);
        if(k == 0) return res;

        priority_queue<int> que;
        for(int i = 0; i < k; i++)
        {
            que.push(arr[i]);
        }

        for(int i = k; i < arr.size(); i++)
        {
            if(que.top() > arr[i])
            {
                que.pop();
                que.push(arr[i]);
            }
        }

        for(int i = 0; i < k; i++)
        {
            res[i] = que.top();
            que.pop();
        }

        return res;
    }
};