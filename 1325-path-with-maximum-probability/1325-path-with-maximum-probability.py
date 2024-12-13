class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        # Build the adjacency list with weight attribute
        adj = [ [] for _ in range(n) ]
        for i in range(len(edges)):
            u, v = edges[i]
            weight = succProb[i]
            adj[u].append((v, weight))
            adj[v].append((u, weight))

        # Reverse Dijkstra
        dist = [0] * n
        q = []
        heappush(q, (1, start_node))

        while q:
            p, u = heappop(q)

            if -p <= dist[u]:  # I think == does not work bc of floating point precision?
                for v, weight in adj[u]:
                    # probability calculation instead of weight
                    if dist[u] == 0 or dist[u] == 1:
                        d = weight
                    else:
                        d = dist[u] * weight
    
                    # reversed if statement and negative push because we are finding maximum instead of shortest
                    if d > dist[v]:
                        dist[v] = d
                        heappush(q, (-d, v))
        
        return dist[end_node]