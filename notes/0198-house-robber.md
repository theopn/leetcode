# 198. House Robber

## Relevant Skills

- Tabulation

## Approach

```
[2 7 9 3 1]
 |
Best you could do is 2

[2 7 9 3 1]
   |
 2 v.s. *7*

[2 7 9 3 1]
     |
*2+9* v.s. 7

[2 7 9 3 1]
       |
*7 + 3* v.s. 11 (2 + 9 from the prev iteration)

[2 7 9 3 1]
         |
*11 + 1 (2 + 9 + 1)* v.s. 10 (7 + 3 from the prev iteration)
```

0. DP[i] is maximum between DP[i - 1] or DP[i - 2] + nums[i]

## Optimization

## Pseudocode

```lua
function rob(nums)
    if n == 0 then return 0
    elseif n == 1 then return nums[1]
    end

    dp = [nums[0], math.max(nums[0], nums[1])]
    for i = 2, n - 1 do
        dp[i] = math.max(dp[i - 1], dp[i - 2] + nums[i])
    end
    return dp[n - 1]
end
```

## Analysis

- $O(n)$, space $O(n)$

## Relevant Coding Skills

- In Python, use `dp = [0] * n + 1` to create an array filled with zero
- In C++, use `std::vector<int> dp(n + 1, 0)` to create an array filled with zero (or you can omit the second param 0 since the vector will be initialized with zero by default)

