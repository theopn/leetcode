# 3. Longest Substring Without Repeating Characters

## Relevant Skills

- Sliding Window
- Hashmap

## Approach

0. Loop through the char in `s` and keep track of the current window length, head, and longest length so far.
    E.g., `[^$a d d f], i = 0, head = 0, window = 0, longest = 0` -> `[^a$ d d f], i = 1, head = 0, window = 1, longest = 1` where `^` and `$` represent the head and tial of the window
0. Add the current character to a hashmap.
    In the iteration for `[^a d$ d f], i = 2, head = 0, window = 2, longest = 2`, hashmap would contain `a, d`
0. If a character is repeated, shrink the window by moving the head forward and subsequently reducing the current window length.
    E.g., `[^a d d$ f], i = 2, head = 0, window = 2, longest = 2`, since `d` is repeated, it becomes `[a d ^d$ f], i = 2, head = 2, window = 1, longest = 2`
0. Return the longest

## Optimization

## Pseudocode

```lua
function longestSubstrWoRepeatingChar(s)
    longest, head, window_len = 0, 0, 0
    hash = {}

    for c in s do
        hash[c]++ --> add the current char to the hashmap
        window_len++ -->  Increase the window length

        if hash[c] == 1 then --> current char isn't repeated
            if window_len > longest then
                longest = window_len
            end
        else --> Current char is repeated
            -- Shrink the window until repeated char is excluded
            while hash[c] > 1 do
                hash[s[head]] -= 1
                head++
                curr -= 1
            end
        end
    end

    return longest
end
```

## Analysis

- Outer loop: $O(n)$
- Inner while loop: $O(n)$
- Technically $O(n^{2})$, but because inner while loop will only be executed once per function, I would say it's closer to $O(n \log (n))$

## Relevant Coding Skills

