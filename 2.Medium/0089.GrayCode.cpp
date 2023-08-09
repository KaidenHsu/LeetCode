// 8/8/23

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1<<n);
        for (int i=0; i<(1<<n); i++)
            ans[i] = i^(i>>1);
        return ans;
    }
};

