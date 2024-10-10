# 392. Is Subsequence

## Relevant Skills

- Two Pointers

## Approach

0. If `s` is length of 0, then `s` is automatically a subsequence of `t`
0. If `s` is longer than `t`, then `s` cannot be a subsequence of `t`
0. Initialize a pointer for characters in `s`
0. Iterate through characters in `t`
0. If the character in `t` matches character in `s` (t[i] == s[ptr]), increment `ptr`
0. When the `ptr` exceeds the length of `s`, return true

## Optimization

## Pseudocode

```lua
function is_subsequence(s, t)
    if s.n == 0 then return true end
    if s.n > s.t then return false end

    ptr = 0
    for c in t do
        if c == s[ptr] then
            ptr += 1
            if ptr >= s.n then return true end
        end
    end
    return false
end
```

## Analysis

$O(n)$

## Relevant Coding Skills

