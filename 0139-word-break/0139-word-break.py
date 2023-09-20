class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        #dp = [False] * (len(s) + 1)
        #dp[0] = True
        #for i in range(len(s)):
        #    if dp[i]:
        #        for j in range(i + 1, len(s) + 1): # s[i:j] is substr of s [i, j)
        #            if s[i:j] in wordDict:
        #                dp[j] = True
        #return dp[-1]

        dp = [False] * (len(s) + 1)
        dp[0] = True
        for i in range(len(s) + 1): # s[j:i] is substr of s [j, i)
            for j in range(i):
                if dp[j]:
                    if s[j:i] in wordDict:
                        dp[i] = True
        return dp[len(s)]
