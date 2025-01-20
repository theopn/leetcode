class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        # stuck in the first cell
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1

        m, n = len(grid), len(grid[0])
        v = m * n
        adj = [ [] for _ in range(v) ]

        for i in range(m):
            for j in range(n):
                if i > 0:
                    adj[(i * n) + j].append( ( ((i - 1) * n) + j, grid[i -1][j] ) )
                if i < m - 1:
                    adj[(i * n) + j].append( ( ((i + 1) * n) + j, grid[i +1][j] ) )
                if j > 0:
                    adj[(i * n) + j].append( ( (i * n) + (j - 1), grid[i][j - 1] ) )
                if j < n - 1:
                    adj[(i * n) + j].append( ( (i * n) + (j + 1), grid[i][j + 1] ) )

        # dijkstra
        dist = [ float("inf") ] * v
        dist[0] = 0

        pq = []
        heappush(pq, (0, 0))

        while pq:
            timesofar, node = heappop(pq)

            if timesofar == dist[node]:
                for adjnode, mintime in adj[node]:
                    
                    # we might have to go back and force between previous cell
                    if (mintime - timesofar) % 2 == 0:
                        mintime += 1
                    candidate = max(mintime, timesofar + 1)

                    if candidate < dist[adjnode]:
                        dist[adjnode] = candidate
                        heappush(pq, (candidate, adjnode))

        return dist[v - 1]