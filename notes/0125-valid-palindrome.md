# 125. Valid Palindrome

## Relevant Skills

- Two Pointers

## Approach

0. Initialize pointers at the beginning and the end of the array
0. Loop while the beginning pointer is greater than or equal to the end pointer.
    This way, it accounts for both odd and even length strings.
0. If `s[i]` or `s[j]` isn't alphanumeric character, skip it by incrementing/decrementing `i`
0. If lowercase `s[i]` and `s[j]` are not equal to each other, return false
0. Otherwise, increment `i` and decrement `j` for the next iteration

## Optimization

## Pseudocode

```lua
function is_palindrome(s)
    i = 0, j = s.n - 1

    while i <= j do
        if not s[i]:match("%w") then
            i += 1
        elseif not s[j]:match("%w") then
            j -= 1
        elseif s[i] ~= s[j] then
            return false
        else
            i += 1
            j -= 1
        end
    end

    return true
end
```

## Analysis

Worst case scenario (i.e., string filled with non-alphanumeric character "!@#$%%"), loop will iterate until `i == j == s.n - 1`.
Thus, $O(n)$

## Relevant Coding Skills

