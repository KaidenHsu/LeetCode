// 7/29/23

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;

        for (int num: nums){
            set.insert(num);
        }

        int longestConsecutiveSequence = 0;

        for (int num: nums){
            if (set.find(num-1) == set.end()){
                int currentNumber = num;
                int currentConsecutiveSequence = 1;

                while (set.find(currentNumber+1) != set.end()){
                    currentNumber++;
                    currentConsecutiveSequence++;
                }

                longestConsecutiveSequence = max(longestConsecutiveSequence, currentConsecutiveSequence);
            }
        }

        return longestConsecutiveSequence;
    }
};
