class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        # Initialize dist array with infinity so that non-existent edge weights become infinity
        # BE CAREFUL WITH USING * operator, i.e, dist = [[float("inf")] * n] * n
        # You are referencing the same [[float("inf")] * n] n times essentially
        dist = [ [float("inf") for _ in range(n)] for _ in range(n) ]

        # Set the edge matrix for existing edges
        for u, v, w in edges:
            dist[u][v] = w
            dist[v][u] = w

        # Set 0 for self
        for i in range(n):
            dist[i][i] = 0

        # Find the all-pairs shortest path
        for k in range(0, n):
            for i in range(0, n):
                for j in range(0, n):
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

        for i in dist:
            print('\t'.join(map(str, i)))

        # Calculate cities reachable within the threshold
        minimum = float("inf")
        minimumCity = 0
        for i in range(n):
            numreachable = 0
            for j in range(n):
                if i == j:
                    continue
                if dist[i][j] <= distanceThreshold:
                    numreachable += 1
                
            print(f"City {i} can reach {numreachable} cities")
            if numreachable <= minimum:
                minimum = numreachable
                minimumCity = i

        return minimumCity