#define MIN(a, b) ((a) < (b)? (a) : (b))

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for(int i = 2; i < cost.size(); i++)
            cost[i] += MIN(cost[i - 1], cost[i - 2]);
        
        return MIN(cost[cost.size() - 1], cost[cost.size() - 2]);
    }
};