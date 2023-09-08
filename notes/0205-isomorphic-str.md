# 205. Isomorphic Strings

## Relevant Skills

- Hashmap
- Checking if key exists

## Approach

0. Check if length are not equal to each other
0. Initialize a hashmap that maps a character in `s` to a character in `t`
0. Iterate through the length of the string
0. If `s[i]` does not exist in the map, map `s[i]` to `t[i]`
0. Else, check if `map[s[i]] == t[i]`.
    If not, return false
0. Repeat this process, but check the other way around
    - You can do this in a separate loop or if statement within the same loop
    - This is necessary for inputs like `badc` and `baba`

## Optimization

- There has to be a way to do this with out repeating the same code twice

## Pseudocode

```lua
function is_isomorphic(s, t)
    if s.n ~= t.n then return false end

    s_to_t = {}
    t_to_s = {}

    for i, v in ipairs(s) do
        if s_to_t[s[i]] == nil then
            s_to_t[s[i]] = t[i]
        elseif s_to_t[s[i]] ~= t[i] then
            return false
        end

        if t_to_s[t[i]] == nil then
            t_to_s[t[i]] = s[i]
        elseif t_to_s[t[i]] ~= s[i] then
            return false
        end
    end

    return true
end
```

## Analysis

- $O(n)$

## Relevant Coding Skills

