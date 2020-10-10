class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        
        int i = 0;
        int j = matrix[0].size() - 1;

        while(i < matrix.size() && j >= 0)
        {
            if(target < matrix[i][j])
            {
                j--;
            }

            else if(target > matrix[i][j])
            {
                i++;
            }

            else return true;
        }

        return false;
    }
};