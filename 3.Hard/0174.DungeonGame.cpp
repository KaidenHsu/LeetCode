// 7/25/22
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<int> dp(dungeon.size() + 1, INT_MAX);
        dp[dungeon.size() - 1] = 1;

        for(int i = dungeon[0].size() - 1; i >= 0; i--)
            for(int j = dungeon.size() - 1; j >= 0; j--)
                dp[j] = max(1, min(dp[j], dp[j + 1]) - dungeon[j][i]);
        
        return dp[0];
    }
};