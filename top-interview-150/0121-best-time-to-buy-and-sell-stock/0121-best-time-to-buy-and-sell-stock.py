class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        min_price = prices[0]
        
        for right in range(1, len(prices)):
            profit = prices[right] - min_price
            
            if profit > max_profit:
                max_profit = profit
                
            if prices[right] < min_price:
                min_price = prices[right]
                
        return max_profit
