// 6/20/23

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int left = 0, right = height.size()-1;

        while (left < right) {
            int volume = min(height[left], height[right]) * (right - left);
            if (volume > max) max = volume;

            int i;

            if (height[left] <= height[right]) {
                for (int i = left+1; i <= right; i++) {
                    if (height[i] > height[left] || i == right) {
                        left = i;
                        break;
                    }
                }
            } else {
                for (int i = right-1; i >= left; i--) {
                    if (height[i] > height[right] || i == left) {
                        right = i;
                        break;
                    }
                }
            }
        }

        return max;
    }
}
