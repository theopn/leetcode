class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        q = deque()
        dist = [ [-1] * n for _ in range(m) ]

        # enqueue starting points: cells in the first column
        for i in range(m):
            dist[i][0] = 0
            q.append((i, 0))

        maxMovess = 0
        while q:
            i, j = q.popleft()
            # let's see the distance to reach this cell is the maximum
            maxMovess = max(maxMovess, dist[i][j])

            # traverse adjacent cells
            for direction in [-1, 0, 1]:
                ii, jj = i + direction, j + 1
                # if the new coordinate is valid and not visited and strictly greater
                if (0 <= ii and ii < m
                    and 0 <= jj and jj < n
                    and dist[ii][jj] == -1
                    and grid[i][j] < grid[ii][jj]):
                    dist[ii][jj] = dist[i][j] + 1
                    q.append((ii, jj))

        return maxMovess