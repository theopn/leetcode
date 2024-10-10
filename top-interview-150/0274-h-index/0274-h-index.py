class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort()
        
        h = 0
        n = len(citations)
        for i in range(n):
            candidate = min(citations[i], n - i)
            if h < candidate:
                h = candidate
                
        return h