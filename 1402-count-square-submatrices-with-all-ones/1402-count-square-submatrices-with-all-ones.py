class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        dp = [ [0] * (n + 1) for _ in range(m + 1) ]

        for i in range(m):
            for j in range(n):
                # 1. [i][j]: diagnoally above cell, [i][j + 1] above cell, dp[i + 1][j] left cell
                # 2. "+ matrix[i][j]" is same as if matrix[i][j] == 1: ... + 1
                if matrix[i][j] == 1:
                    dp[i + 1][j + 1] = min(dp[i][j], dp[i][j + 1], dp[i + 1][j]) + 1

        summ = 0
        for i in range(m + 1):
            for j in range(n + 1):
                summ += dp[i][j]

        return summ