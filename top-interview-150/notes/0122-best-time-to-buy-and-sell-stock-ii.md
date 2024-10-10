# 122. Best Time to Buy and Sell Stock II

## Relevant Skills

- Greedy algorithm

## Approach

If there's a positive profit, buy and sell the next day
You are re-buying a stock no matter what..

```
e.g.: [1 2 3 4 5]
i = 1: Buy @ 1 (day 0), sell @ 2 (day 1)
i = 2: Buy @ 2 (day 1), sell @ 3 (day 2)
...
e.g.: [7 1 5 3 6 4]
i = 1: Buy @ 7, hold @ 1 (i.e., sold @ 7 yesterday)
i = 2: Buy @ 1, sell @ 5
...
```

## Optimization

## Pseudocode

```lua
function max_profit(prices)
    profit = 0
    for i = 1, prices.n - 1 do
        todays_profit = prices[i] - prices[i - 1]
        if todays_profit > 0 then --> or check prices[i] > prices[i - 1]
            profit += todays_profit
        end
    end
    return profit
end
```

## Analysis

- $O(n)$

## Relevant Coding Skills

