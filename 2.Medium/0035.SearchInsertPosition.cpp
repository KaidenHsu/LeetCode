// 7/14/22
class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int left, int right){
        if(left > right) return left;
        
        if(left == right)
            if(nums[left] < target) return left + 1;
            else return left;
        
        int mid = (left + right) / 2;
        if(nums[mid] < target) return binarySearch(nums, target, mid + 1, right);
        
        return binarySearch(nums, target, left, mid);
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};