// 6/22/23

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // build min array (front -> end)
        vector<int> min_arr(prices.size(), 0);
        int min = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < min) min = prices[i];
            min_arr[i] = min;
        }

        // build max array (end -> front)
        vector<int> max_arr(prices.size(), 0);
        int max = 0;
        for (int i = prices.size()-1; i >= 0; i--) {
            if (prices[i] > max) max = prices[i];
            max_arr[i] = max;
        }

        // the answer is the maximum value of (max_arr[i]-min_arr[i])
        int ans = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (max_arr[i] - min_arr[i] > ans)
                ans = max_arr[i] - min_arr[i];
        }

        return ans;
    }
};
