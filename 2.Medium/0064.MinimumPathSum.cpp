// 7/23/22
class Solution {
public:
    int minCost(vector<vector<int>> &cost,int m, int n,vector<vector<int>>& mem) { 
      if (n < 0 || m < 0) return INT_MAX; 
      else if(m == 0 && n == 0) return cost[m][n]; 
      if(mem[m][n] != -1) return mem[m][n];

      return mem[m][n] = cost[m][n] + min(minCost(cost, m - 1, n, mem), minCost(cost, m, n - 1, mem));
    } 
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> mem(m, vector<int>(n, -1));
        return minCost(grid, m - 1, n - 1, mem);
    }
    
};