class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        v = m * n

        # vertices are numbered like following:
        # |0|1|2|3|
        # |4|5|...
        # the cell at (i, j) is ((i * n) + j)th cell
        adj = [ [] for _ in range(v) ]
        # |0|0|1|0|
        # |1|0|1|0|
        # graph looks like this for the grid above
        # |0| 0-> <-0 |0| 1-> <-0 |1| 0-> <-1 |0|
        #  1           0           1           0
        #  v           v           v           v
        #  ^           ^           ^           ^
        #  0           0           1           0
        # |1| 0-> <-1 |0| 1-> <-0 |1| 0-> <-1 |0|
        for i in range(m):
            for j in range(n):
                # up
                if i > 0:
                    if grid[i - 1][j] == 0:
                        adj[(i * n) + j].append(( ((i - 1) * n) + j, 0 ))
                    else:
                        adj[(i * n) + j].append(( ((i - 1) * n) + j, 1 ))
                # down
                if i < m - 1:
                    if grid[i + 1][j] == 0:
                        adj[(i * n) + j].append(( ((i + 1) * n) + j, 0 ))
                    else:
                        adj[(i * n) + j].append(( ((i + 1) * n) + j, 1 ))
                # left
                if j > 0:
                    if grid[i][j - 1] == 0:
                        adj[(i * n) + j].append(( (i * n) + (j - 1), 0 ))
                    else:
                        adj[(i * n) + j].append(( (i * n) + (j - 1), 1 ))
                # right
                if j < n - 1:
                    if grid[i][j + 1] == 0:
                        adj[(i * n) + j].append(( (i * n) + (j + 1), 0 ))
                    else:
                        adj[(i * n) + j].append(( (i * n) + (j + 1), 1 ))
                        
        # dijkstra
        dist = [ float("inf") ] * v
        dist[0] = 0

        pq = []
        heappush(pq, (0, 0))

        while pq:
            priority, node = heappop(pq)

            if priority == dist[node]:
                for adjnode, weight in adj[node]:
                    candidate = dist[node] + weight
                    if candidate < dist[adjnode]:
                        dist[adjnode] = candidate
                        heappush(pq, (candidate, adjnode))

        return dist[v - 1]