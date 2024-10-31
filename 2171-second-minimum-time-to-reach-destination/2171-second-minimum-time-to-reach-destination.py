class Solution:
    def secondMinimum(self, n: int, edges: List[List[int]], time: int, change: int) -> int:
        # Build an adjacency list
        # 1: [2, 3, 4]
        # 2: [1]
        # ...
        adj = [ [ ] for _ in range(n + 1) ]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        q = []
        heapify(q)

        dist1 = [float("inf")] * (n + 1)
        dist1[1] = 0
        heappush(q, (0, 1))
        dist2 = [float("inf")] * (n + 1)

        while q:
            timesofar, node = heappop(q)


            if timesofar == dist1[node] or timesofar == dist2[node]:
                if (timesofar // change) % 2 == 1:  # Red light if it is odd
                # change * (how many times light has changed + 1) + time
                    timesofar = change * (timesofar // change + 1) + time
                else:
                    timesofar += time

                for v in adj[node]:
                    if timesofar < dist1[v]:
                        dist2[v] = dist1[v]
                        dist1[v] = timesofar
                        heappush(q, (timesofar, v))
                    elif timesofar < dist2[v] and dist1[v] != timesofar:
                        dist2[v] = timesofar
                        heappush(q, (timesofar, v))
                
                #print(f"v: {v}, dist1: {dist1}, dist2: {dist2}, timesofar: {timesofar}")

        return dist2[n]