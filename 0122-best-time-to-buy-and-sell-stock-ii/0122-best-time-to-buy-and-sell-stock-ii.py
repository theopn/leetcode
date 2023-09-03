class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # If there's a positive profit, buy and sell the next day
        # [1 2 3 4 5]
        # i = 2: Buy @ 1, sell @ 2
        # i = 3: Buy @ 2, sell @ 3
        # ... You get the intuition right
        profit = 0
        for i in range(1, len(prices)):
            todays_profit = prices[i] - prices[i - 1]
            if todays_profit > 0:
                profit += todays_profit
                
        return profit
                
        