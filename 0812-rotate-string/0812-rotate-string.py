class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        n, m = len(s), len(goal)
        if n != m:
            return False

        # append s to itself
        s += s
        n = len(s)

        def failure(p):
            lps = [0] * m
            j = 0
            for i in range(1, m):
                while j > 0 and p[i] != p[j]:
                    j = lps[j - 1]
                if p[i] == p[j]:
                    j += 1
                lps[i] = j

            return lps

        lps = failure(goal)
        # KMP
        i, j = 0, 0
        while i < n:
            if s[i] == goal[j]:
                if j == m - 1:
                    return True
                else:
                    i += 1
                    j += 1
            elif j > 0:
                j = lps[j - 1]
            else:
                i += 1

        return False