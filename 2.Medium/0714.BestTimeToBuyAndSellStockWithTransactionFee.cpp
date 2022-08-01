// 8/1/22
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // define empty state and hold state
        int hold = -prices[0], empty = 0; 

        for(int i = 1; i < prices.size(); i++) {
            // the max profit of hold state is either we still hold the stock we hold at the i-1 time or we buy new stock(empty - prices[i])
            hold = max(hold, empty - prices[i]);
            // the max profit of enpty state is eighter we still keep our hand empty or we sell the stock we already hold(hold + prices[i] - fee)
            empty = max(empty, hold + prices[i] - fee);
        }

        // return must be empty, because selling is better than holding one stock that has not been sold
        return empty;
    }
};