// 7/14/22
class Solution {
public:
    vector<vector<int>> res;

    // Backtracking
    void permutation(vector<int> &nums,int i,int n){
        if(i == n){
            res.push_back(nums);
            return;
        }

        for(int j = i; j <= n; j++){
            swap(nums[i], nums[j]);
            permutation(nums, i + 1, n);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums){
        permutation(nums, 0, nums.size() - 1);

        return res;
    }
};

