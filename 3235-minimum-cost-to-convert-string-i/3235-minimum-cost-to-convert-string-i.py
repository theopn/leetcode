class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        # Initialize dist array with infinity so that non-existent edge weights become infinity
        # BE CAREFUL WITH USING * operator, i.e, dist = [[float("inf")] * n] * n
        # You are referencing the same [[float("inf")] * n] n times essentially
        dist = [ [float("inf") for _ in range(26)] for _ in range(26) ]

        # Existing edges
        # Conversion:
        # ord('a') - 97 = 0
        # chr(0 + 97) = 'a'
        for i in range(len(original)):  # == len(changed) == len(cost)
            u = ord(original[i]) - 97
            v = ord(changed[i]) - 97
            w = cost[i]
            print(f"u: {u} v: {v} w: {w}")
            # Same pair in original and changed can appear wiht diff cost,
            # take the smaller
            dist[u][v] = min(dist[u][v], w)

        # itself
        for i in range(26):
            dist[i][i] = 0

        # Find the shortest path for 
        for k in range(26):
            for i in range(26):
                for j in range(26):
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

        for i in dist:
            print('\t'.join(map(str, i)))

        total = 0
        for i in range(len(source)):  # == len(target)
            cost = dist[ord(source[i]) - 97][ord(target[i]) - 97]
            if (cost >= float("inf")):
                return -1
            total += cost

        return total