// 7/13/22
class Solution {
public:
    int jump(vector<int>& nums) {
        nums[nums.size() - 1] = 0;
        
        for(int i = nums.size() - 2; i >= 0; i--){
            if(nums[i] == 0) nums[i] = INT_MAX;
            else{
                int min = INT_MAX, range = nums[i];
                nums[i] = min;
                for(int j = 1; j <= range && i + j < nums.size(); j++)
                    if(nums[i + j] < min){
                        nums[i] = nums[i + j];
                        min = nums[i + j];
                    }
                
                if(nums[i] != INT_MAX) nums[i]++;
            }
        }
        
        return nums[0];
    }
};