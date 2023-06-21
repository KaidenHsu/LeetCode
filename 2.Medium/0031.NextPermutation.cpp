// 6/21/23

class Solution {
public:
    void reverse (int start, int end, vector<int> &nums) {
        int i = start, j = end;

        while (i < start+(end-start+1)/2) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }

    void nextPermutation(vector<int>& nums) {
        int marker = nums.size() - 1;

        while (marker >= 1 && nums[marker-1] >= nums[marker]) {
            marker--;
        }

        // edge case
        if (marker == 0) {
            // return the ascending order of the vector
            reverse(0, nums.size()-1, nums);
            return;
        }

        // numbers after nums[marker] are sorted in descending order
        // i.e. marker = 2, nums = {5, 3, 4, 5, 4, 2}
        marker--;

        // binary search in the descending part of the vector for the
        // number that is immediately strictly greater than nums[marker]
        int immediately_greater = marker, start = marker + 1, end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] <= nums[marker]) {
                end = mid - 1;
            } else {
                immediately_greater = mid;
                start = mid + 1;
            }
        }

        // swap nums[marker] and nums[immediately_greater]
        swap(nums[marker], nums[immediately_greater]);

        // reverse the order from nums[marker+1] to nums[nums.size()-1]
        // descedning -> ascending, an amount of [(nums.size()-1)-(marker+1)+1] items
        reverse(marker+1, nums.size()-1, nums);
    }
};
