class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        hashbrown = {}
        for i in range(len(s)):
            if not s[i] in hashbrown:
                hashbrown[s[i]] = t[i]
            elif hashbrown[s[i]] != t[i]:
                return False
            
        hashbrown = {}
        for i in range(len(t)):
            if not t[i] in hashbrown:
                hashbrown[t[i]] = s[i]
            elif hashbrown[t[i]] != s[i]:
                return False
            
        return True
        