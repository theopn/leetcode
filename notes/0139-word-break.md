# 139. Word Break

## Relevant Skills

- DP
- Substring

## Approach

0. Initialize a DP array filled with false.
    DP[0] means substring from 0 to 0 can be broken down into words in dict.
    So make DP[0] true
0. Loop through i until s.n
0. Loop through j until i
0. Check if DP[j] is true
0. If so, check if substring from j to i is in the word dictionary
0. If so, mark DP[i] as true
0. Out of the loop, return DP[s.n]

## Optimization

You can do this two ways:

1. Loop j in [0, i) (procedure described in the Approach)
2. Loop j in (i, s.n]

The first way is faster, but I will include the second way in the pseudocode comment

## Pseudocode

```lua
function word_break(s, dict)
    dp = [true] --> length s.n + 1
    for i = 0, s.n do
        for j = 0, i - 1 do
            if dp[j] then
                if s.sub(j, i) in dict then --> substr in [j, i)
                    dp[i] = true
                end
            end
        end
    end

    --for i = 0, s.n - 1 do
    --    if dp[i] then
    --        for j = i + 1, s.n do
    --            if s.sub(i, j) in dict then
    --                dp[j] = true
    --            end
    --        end
    --    end
    --end
    return dp[s.n]
end
```

## Analysis

- $O(n^{2})$ for the number of iteration, but if we include the time it takes to get the substring, $O(n^{3})$

## Relevant Coding Skills

- In Python, `print("hello"[1:3])` prints "el"

