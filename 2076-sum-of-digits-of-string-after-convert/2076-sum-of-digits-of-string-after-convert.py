class Solution:
    def getLucky(self, s: str, k: int) -> int:
        nu = ""
        
        for c in s:
            nu += str(ord(c) - 96)
        
        nu = int(nu)
        
        for i in range(k):
            su = 0
            while nu > 0:
                su += nu % 10
                nu //= 10
            nu = su
                
        return nu