// 8/15/22
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return true;
            
            if((nums[l] == nums[mid]) && (nums[r] == nums[mid])) { // duplicates
                l++;
                r--;
            } else if(nums[l] <= nums[mid]){ // target is in first  half
                if((nums[l] <= target) && (nums[mid] > target)) r = mid - 1;
                else l = mid + 1;
            } else { // target is in second half
                if((nums[mid] < target) && (nums[r]>= target)) l = mid + 1;
                else r = mid - 1;
            }
        }
        
        return false;
    }
};