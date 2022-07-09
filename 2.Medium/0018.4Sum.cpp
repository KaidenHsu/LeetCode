class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            for(int j = i + 1; j < nums.size(); j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                long sum1 = target - nums[i] - nums[j] * 1L;
                int low = j + 1, high = nums.size() - 1;

                while(low < high){
                    int sum2 = nums[low] + nums[high];
                    
                    if(sum2 < sum1) low++;
                    else if(sum2 > sum1) high--;
                    else{
                        res.push_back({nums[i], nums[j], nums[low], nums[high]});

                        int lowDup = nums[low];
                        while(low < high && nums[low] == lowDup) low++;
                        
                        int highDup = nums[high];
                        while(high > low && nums[high] == highDup) high--;
                    }
                }
            }
        }

        return res;
    }
};