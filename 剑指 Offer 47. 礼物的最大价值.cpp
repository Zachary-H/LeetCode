class Solution {
public:
    int maxValue(vector<vector<int>>& grid) 
    {
        if(grid.size() == 0 || grid[0].size() == 0)
        {
            return 0;
        }

        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int> (col, 0));

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                int up = 0;
                int left = 0;

                if(i > 0) up = dp[i-1][j];
                if(j > 0) left = dp[i][j-1];

                dp[i][j] = max(up, left) + grid[i][j];
            }
        }

        return dp[row-1][col-1];
    }
};