class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if len(s) == 0: return True
        if len(s) > len(t): return False
        ptr = 0
        for c in t:
            if c == s[ptr]:
                ptr += 1
                if ptr >= len(s):
                    return True
                
        return False