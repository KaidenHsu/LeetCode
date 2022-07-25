// 7/10/22
class Solution {
public:
    int memo[100][100][21];
    const int MAX_COST = 1000001;

    int findMinCost(vector<int>& houses, vector<vector<int>>& cost, int targetCount, int currIndex, int neighborhoodCount, int prevHouseColor) {
        // If all houses are traversed, check if the neighbor count is as expected or not
        if(currIndex == houses.size()) return neighborhoodCount == targetCount? 0 : MAX_COST;

        // If the neighborhoods are more than the threshold, we can't have target neighborhoods
        if(neighborhoodCount > targetCount) return MAX_COST;

        if(memo[currIndex][neighborhoodCount][prevHouseColor] != -1) return memo[currIndex][neighborhoodCount][prevHouseColor];

        int minCost = MAX_COST, newNeighborhoodCount, currCost;
        if(houses[currIndex]){ // If the house is already painted, update the values accordingly
            newNeighborhoodCount = neighborhoodCount + (houses[currIndex] != prevHouseColor);
            minCost = findMinCost(houses, cost, targetCount, currIndex + 1, newNeighborhoodCount, houses[currIndex]);
        }else // If the house is not painted, try every possible color and store the minimum cost
            for(int color = 1; color <= cost[0].size(); color++){
                newNeighborhoodCount = neighborhoodCount + (color != prevHouseColor);
                currCost = cost[currIndex][color - 1] + findMinCost(houses, cost, targetCount, currIndex + 1, newNeighborhoodCount, color);
                minCost = min(minCost, currCost);
            }

        return memo[currIndex][neighborhoodCount][prevHouseColor] = minCost;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(memo, -1, sizeof(memo));
        
        return findMinCost(houses, cost, target, 0, 0, 0) == MAX_COST ? -1 : findMinCost(houses, cost, target, 0, 0, 0);
    }
};