class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if n * m != len(original):
            return []

        matrix = [ [ None for _ in range(n)] for _ in range(m) ]
        for i in range(len(original)):
            matrix[i // n][i % n] = original[i]
            
        return matrix