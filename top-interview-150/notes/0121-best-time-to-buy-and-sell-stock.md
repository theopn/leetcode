# 121. Best Time to Buy and Sell Stock

## Relevant Skills

- Sliding window
- Kadane's Algorithm

## Approach

Sliding window:

0. Keep track of maximum profit and minimum price so far (set minimum price to `prices[0]`)
0. Iterate from 1 to the end of the prices array
0. Calculate the current profit (`prices[i] - min_price`)
0. If it's greater than the current `max_profit`, update
0. If `prices[i]` is smaller than the `min_price`, update

Kadane's Algorithm.
It is almost identical to the original Kadane's algorithm (version with empty subarray admitted) for the maximum subarray problem, but current sum is calculated between maximum of 0 and `curr + prices[i] - prices[i - 1]` (instead of 0 and `curr + num`).
Basically, if we are making a profit, we keep add it the profit.
When we face the point where we are not making any profit (negative profit), we reset to 0.

## Optimization

## Pseudocode

Sliding window:

```lua
function max_profit(prices)
    max_profit, min_price = 0, prices[0]

    for i = 1, prices.n - 1 do
        curr_profit = prices[n] - min_price

        if curr_profit > max_profit then max_profit = curr_profit end
        if prices[n] < min_price then min_price = prices[n] end
    end

    return max_profit
end
```

Kadane's Algorithm:

```lua
function max_profit(prices)
    best_sum, curr_sum = 0, 0
    for i = 1, prices.n - 1 do --> Regular Kadane's algo would loop through `num` in `nums`
        curr_sum = math.max(0, curr_sum + prices[i] - prices[i - 1]) --> Regular Kadane's algo would compare (0, curr_sum + num)
        best_sum = math.max(curr_sum, best_sum)
    end
    return bet_sum
end
```

## Analysis

- $O(n)$

## Relevant Coding Skills

