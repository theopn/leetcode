# 20. Valid Parentheses

## Relevant Skills

- Stack operation
- Dictionary

## Approach

0. Initialize dictionary for parenthesis pairs (`{ ( : ), { : }, [ : ] }`)
0. Initialize an empty stack
0. Iterate through character
0. If character is an opening parenthesis, push to the stack
0. Else (or else if it's closing parenthesis), first check if stack is empty.
    If so return false
0. Pop an element and see if the current char is `hash[st.pop]`.
    If not, return false
0. Out of the loop, return if the stack is empty.
    This is for the case where the string only contains opening parentheses (e.g., "({"), so false was never returned in the loop and only stack was modified.

## Optimization

- Check if the length is odd in the beginning and return false

## Pseudocode

```lua
function is_valid(s)
    if s.n % 2 ~= 0 then return false end

    pairs = {
        ['('] = ')',
        ['{'] = '}',
        ['['] = ']',
    }
    stack = {}

    for c in s do
        if c == '(' or c == '{' or c == '[' then
            stack.push(c)
        else --> or else if c == closing bracket
            if stack.empty() then return false end
            opening = stack.pop()
            if c ~= pairs[opening] then return false end
        end
    end

    return stack.empty()
end
```

## Analysis

- $O(n)$

## Relevant Coding Skills

- In C++, define dictionary like so:
    ```cpp
    unordered_map<char, char> pairs{
        { '(', ')' },
        { '{', '}' },
        { '[', ']' },
    };
    ```
- In C++, use `stack<char>` and `push()`, `top()`, `pop()`, `empty()` operations

