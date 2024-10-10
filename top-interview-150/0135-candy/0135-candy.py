class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        candies = [1] * n

        # Check if the current is higher than the right elem
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                candies[i] = candies[i - 1] + 1
        
        # Check if the current is higher than the left elem
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
              candies[i] = max(candies[i], candies[i + 1] + 1)

        return sum(candies)