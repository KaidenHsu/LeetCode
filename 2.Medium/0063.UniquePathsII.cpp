// 8/2/22
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = size(grid), n = size(grid[0]);
        grid[0][0] ^= 1;  // if no obstacle at start, we can reach here in 1 way
        
        // For each cell of first row and column, we can either reach that cell in 1 way
        // if previous column/row cell are not obstacle respectively, or not reach it at all.
        for(int i = 1; i < n; i++) grid[0][i] = !grid[0][i] & grid[0][i - 1]; // we can reach 
        for(int i = 1; i < m; i++) grid[i][0] = !grid[i][0] & grid[i - 1][0];

        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)            
                grid[i][j] = !grid[i][j] ? grid[i - 1][j] + grid[i][j - 1] : 0;                    

        return grid[m - 1][n - 1];
    }
};