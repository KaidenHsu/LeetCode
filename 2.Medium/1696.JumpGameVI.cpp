class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxJumps;
        int n = nums.size() - 1;
        
        maxJumps.push({nums[n], n});
        for(int i = n - 1; i >= 0; --i){
            while(maxJumps.size() && maxJumps.top().second-i > k)  maxJumps.pop();
            
            nums[i] += maxJumps.top().first;
            maxJumps.push({nums[i], i});
        }
        
        return nums[0];
    }
};