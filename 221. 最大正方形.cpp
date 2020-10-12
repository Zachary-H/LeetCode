class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        int maxLen = 0;

        for(int i = 0; i < row; i++)
        {
            if(matrix[i][0] == '1')
            {
                dp[i][0] = 1;
            }
            else
            {
                dp[i][0] = 0;
            }

            maxLen = max(maxLen, dp[i][0]);
        }

        for(int j = 0; j < col; j++)
        {
            if(matrix[0][j] == '1')
            {
                dp[0][j] = 1;
            }
            else{
                dp[0][j] = 0;
            }

            maxLen = max(maxLen, dp[0][j]);
        }

        for(int i = 1; i < row; i++)
        {
            for(int j = 1; j < col; j++)
            {
                if(matrix[i][j] == '1')
                {
                    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }
        return maxLen * maxLen;
    }
};