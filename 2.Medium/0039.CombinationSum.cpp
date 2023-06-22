// 6/22/23

class Solution {
private:
    void helper (vector<int>& candidates, vector<int>& curr, set<vector<int>>& result, int target) {
        if (target == 0) {
            vector<int> tmp(curr.begin(), curr.end());
            sort(tmp.begin(), tmp.end());
            result.insert(tmp);
        }

        for (int c: candidates) {
            if (c <= target) {
                curr.push_back(c);
                helper(candidates, curr, result, target-c);
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> result;
        vector<int> curr;

        helper(candidates, curr, result, target);

        return vector<vector<int>>(result.begin(), result.end());
    }
};
