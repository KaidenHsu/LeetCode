class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        int sum;
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++)
            for(int j = 0; j < i; j++){
                sum = nums[i] + nums[j];
                
                if(sum == target) ans = {i, j};
            }
        
        return ans;
    }
};