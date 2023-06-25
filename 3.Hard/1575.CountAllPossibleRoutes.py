# 6/25/23

class Solution:
    def countRoutes(self, locations: List[int], start: int, finish: int, fuel: int) -> int:
        n = len(locations)
        # Initialize the dp array with 0's. (n rows and fuel + 1 columns)
        # memo[i][j] contains the number of possible routes starting from the city i with j fuel.
        dp = [[0] * (fuel + 1) for _ in range(n)]


        # We initialize the values in the row finish to 1 because just standing at the
        # city is one way to reach finish. It forms the base case for our approach.
        for i in range(fuel + 1):
            dp[finish][i] = 1

        # j: control fuel (0 ~ fuel)
        for j in range(fuel + 1):
            # i: control start city (0 ~ n-1)
            for i in range(n):
                # k: control finsih city (0 ~ n-1)
                for k in range(n):
                    if k == i:
                        continue
                    if abs(locations[i] - locations[k]) <= j:
                        dp[i][j] = (dp[i][j] + dp[k][j - abs(locations[i] - locations[k])]) % 1000000007

        return dp[start][fuel]
