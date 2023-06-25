# 6/25/23

class Solution:
    def tallestBillboard(self, rods: List[int]) -> int:
        dp = {0:0}

        for rod in rods:
            for diff, tallest in list(dp.items()):
                # add the current rod to the shorter support
                new_diff = diff + rod
                new_tallest = tallest + rod
                dp[new_diff] = max(dp.get(new_diff, 0), new_tallest)

                # add the current rod to the taller support
                smaller_rod = tallest - diff + rod
                new_diff = abs(tallest - smaller_rod)
                new_tallest = max(smaller_rod, tallest)
                dp[new_diff] = max(dp.get(new_diff, 0), new_tallest)

        # two supports must be of the same height
        return dp[0]
