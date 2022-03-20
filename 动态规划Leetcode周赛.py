class Solution:
    def maximumBobPoints(self, numArrows: int, aliceArrows: List[int]) -> List[int]:
        # 首先都加1作为背包重量
        aliceArrows = [i+1 for i in aliceArrows]
        #f[i][j]:要选第i个得分,总箭数为j=numArrows
        dp = [[0 for j in range(numArrows+1)] for i in range(12)]
        for i in range(1,12):
            for j in range(1,numArrows+1):
                # 不选第i个物品
                dp[i][j] = dp[i-1][j]
                if j >= aliceArrows[i]:
                    # 在选和不选的情况下选出最大值
                    # 如果不选
                    dp[i][j] = max(dp[i][j],dp[i-1][j-aliceArrows[i]]+i)
        best = [0]*12
        m = 11
        bag_weight = numArrows
        while m>=1:
            i = m
            if(dp[i][bag_weight]==dp[i-1][bag_weight]):
                best[i] = 0
            else:
                best[i] = aliceArrows[i]
                bag_weight -= aliceArrows[i]
            m -= 1
        sum = 0
        for i in best:
            sum += i
        if sum < numArrows:
            best[0] += numArrows - sum
        return best
