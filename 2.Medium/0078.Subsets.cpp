// 6/16/23

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> solutions;
        vector<int> partial_solution;
        check_subsets(nums, solutions, partial_solution, 0);
        return solutions;
    }

    // backtracking
    void check_subsets(vector<int>& nums, vector<vector<int>>& solutions,
    vector<int>& partial_solution, int start) {
        solutions.push_back(partial_solution);

        for (int i = start; i < nums.size(); i++) {
            partial_solution.push_back(nums[i]);
            check_subsets(nums, solutions, partial_solution, i+1);
            partial_solution.pop_back();
        }
    }
};
