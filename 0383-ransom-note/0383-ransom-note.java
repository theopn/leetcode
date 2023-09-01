class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        hashbrown = {}
        for m in magazine:
            hashbrown[m] = hashbrown.get(m, 0) + 1 # get() provides a default val
         
        for r in ransomNote:
            if hashbrown.get(r, 0) == 0:
                return False
            hashbrown[r] -= 1
            
        return True
        