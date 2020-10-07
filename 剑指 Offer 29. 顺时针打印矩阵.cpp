class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0;
        int right = col - 1;
        int top = 0;
        int bottom = row - 1;
        vector<int> ans;

        while(left <= right && top <= bottom)
        {
            for(int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]); 
            }

            for(int i = top+1; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }

            if(left < right && top < bottom)
            {
                for(int i = right-1; i > left ; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }

                for(int i = bottom; i > top ; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
            }

            left++;
            right--;
            top++;
            bottom--;
        }
        
        return ans;
    }
};