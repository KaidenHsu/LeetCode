# 6/25/23

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        uniqNum = 0;

        for idx in nums:
            # XOR
            uniqNum ^= idx;

        return uniqNum
