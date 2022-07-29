// 7/29/22
class Solution {
public:
    int find(vector<int> &prices, int ind, bool buy, int c, int k, vector<vector<vector<int>>> &memo){
        //if buy = 1 means we have to buy now else we have to sell now
        if(ind >= prices.size() || c >= k) return 0; //counter
        else if(memo[ind][buy][c] != -1) return memo[ind][buy][c];
         
        //now we can either buy prices[i] or we can skip it and try next to buy
        if(buy) return memo[ind][buy][c] = max(-prices[ind] + find(prices, ind + 1, !buy, c, k, memo), find(prices, ind + 1, buy, c, k, memo));
        //now we can either sell prices[i] or we can skip it and try next to sell
        else return memo[ind][buy][c] = max(prices[ind] + find(prices, ind + 1, !buy, c + 1, k, memo), find(prices, ind + 1, buy, c, k, memo));
    }
    
    int maxProfit(int k, vector<int>& prices){
        //edge case we are not able to pick 2k points from n points, so we will not reach the limit no matter how we try. 
        //if the price of day i arise, buy the stock in i-1th day and sell it at ith day.
        if (2 * k > prices.size()){
            int res = 0;
            
            for (int i = 1; i < prices.size(); i++)
                res += max(0, prices[i] - prices[i - 1]);
            
            return res;
        }
        
         //here we can do maximum k transaction
        vector<vector<vector<int>>> memo(prices.size() + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return find(prices, 0, 1, 0, k, memo); 
    }
};