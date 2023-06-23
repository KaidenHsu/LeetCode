// 6/23/23
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        // If n is less than or equal to 2, we can immediately return n as the answer
        // since any two elements form a valid arithmetic subsequence.
        if (n <= 2) return n;

        // We initialize the variable longest to 2, as explained earlier
        // the minimum length of an arithmetic subsequence is 2.
        int longest = 2;

        // The purpose of dp is to store the dynamic programming values for the lengths of the
        // arithmetic subsequences ending at each index with different common differences.
        vector<unordered_map<int, int>> dp(n);

        // For each i, we iterate through all previous indices j in the range [0, i-1].
        // This allows us to check all the potential elements that can form an arithmetic subsequence with the element at index i.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // diff represents the common difference of the potential arithmetic subsequence.
                int diff = nums[i] - nums[j];
                // 1. If dp[j].count(diff) returns true, it means we have encountered an arithmetic subsequence
                // ending at index j with the common difference diff. In this case, we update dp[i][diff] to
                // be dp[j][diff] + 1, which extends the subsequence and increments its length by 1.
                // 2. If dp[j].count(diff) returns false, it means we haven't seen an arithmetic subsequence
                // ending at index j with the common difference diff. In this case, we initialize dp[i][diff]
                // to 2 because we have found a new arithmetic subsequence of length 2 (nums[j], nums[i]).
                dp[i][diff] = dp[j].count(diff) ? dp[j][diff] + 1 : 2;

                longest = max(longest, dp[i][diff]);
            }
        }

        return longest;
    }
};
