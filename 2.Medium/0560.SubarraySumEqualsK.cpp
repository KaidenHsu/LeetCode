// 7/20/22
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, count = 0;
        unordered_map<int, int> s;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
            
            if(sum == k) count++;
            if(s.find(sum - k) != s.end()) count += s[sum - k];
            
            s[sum]++;
        } 
        
        return count;
    }
};