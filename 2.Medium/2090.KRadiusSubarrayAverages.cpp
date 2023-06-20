// 6/20/23

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> res(n, -1);
        vector<int> avgs(n, -1);

        if (n <= 2*k) return avgs;
        if (k == 0) return nums;

        res[k] = 0;
        for (int i = 0; i <= 2*k; i++) {
            res[k] += nums[i];
        }

        for (int i = k+1; i <= n-k-1; i++) {
            res[i] = res[i-1] - nums[i-k-1] + nums[i+k];
        }

        for (int i = k; i <= n-k-1; i++) {
            res[i] /= (2*k+1);
        }

        for (int i = 0; i <= n-1; i++) {
            avgs[i] = res[i];
        }

        return avgs;
    }
}
