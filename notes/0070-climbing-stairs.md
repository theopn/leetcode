# 70. Climbing Stairs

## Relevant Skills

- DP

## Approach

Our base cases are:

- When n = 0: there is 0 way
- When n = 1: there is 1 way
- When n = 2: there are 2 ways (1 step + 1 step or 2 steps)

Save these base cases to the DP array.

- When n = 3: we can either take 1 step from n = 2 or 2 steps from n = 1.
    Thus, there are dp[2] + dp[1] = 2 + 1 = 3 ways.
- When n = 4: we can either take 1 step from n = 3 or 2 steps from n = 2.
    Thus, there are dp[3] + dp[2] = 3 + 2 = 5 ways.

## Optimization

## Pseudocode

```lua
function climb_stairs(n)
    if n <= 2 then return n end
    dp = [0, 1, 2] --> size n + 1
    for i = 3, n do
        dp[i] = dp[i - 2] + dp[i - 1]
    end
    return dp[n]
end
```

## Analysis

- $O(n)$, uses $O(n)$ space for the DP array

## Relevant Coding Skills

- In Python, use `dp = [0] * n + 1` to create an array filled with zero
- In C++, use `std::vector<int> dp(n + 1, 0)` to create an array filled with zero (or you can omit the second param 0 since the vector will be initialized with zero by default)

