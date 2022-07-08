class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++){
            // apply the approach of two sum i.e. find the no of pair such that it sums to target
            int low = i + 1, high = nums.size() - 1, target = -nums[i];
            
            while(low < high){
                if(nums[low] + nums[high] == target){ // triplet found
                    res.push_back({nums[i], nums[low], nums[high]});
                                      
                    while(low < high && nums[low] == nums[low + 1]) low++; // skip the duplicates from left                             
                    while(low < high && nums[high] == nums[high - 1]) high--; // skip the duplicates from right 
                    
                    low++;                    
                    high--;
                }else if(nums[low] + nums[high] < target) low++;
                else high--;
            }
                                 
            while(i < nums.size() - 1 && nums[i] == nums[i + 1]) i++; // skip the duplicates
        }
        
        return res;
    }
};