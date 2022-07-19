// 7/19/22
class Solution {
public:
    int fnc(int stairs, int dp[]){
        if(stairs == 1 || stairs == 2) return stairs;
        
        if(dp[stairs - 1]) return dp[stairs - 1];
        
        return dp[stairs - 1] = fnc(stairs - 1, dp) + fnc(stairs - 2, dp);
    }
    
    int climbStairs(int n) {
        int dp[45] = {0};
        return fnc(n, dp);
    }
};