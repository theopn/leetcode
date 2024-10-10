# 49. Group Anagrams

## Relevant Skills

- Hashmap
- String hashmap

## Approach

0. Define a hashmap
0. Iterate through the `str` in `strs`
0. Make a hash representation of characters in string -- this could be a hashmap or sorted string
0. If the hash exists in the hashmap, append to the map
0. Else, make a new array, add the `str`, and map the array to the hash

## Optimization

## Pseudocode

```lua
function group_anagrams(strs)
    hash = {}

    for str in strs do
        h = sort(strs)
        if h in hash then
            hash[h].insert(str)
        else
            hash[h] = [str]
        end
    end

    return list(hash)
end
```

## Analysis

- $O(n * m)$ where $m$ is the length of the longest string in `strs`

## Relevant Coding Skills

- In Python, `"".join(sorted(str))` returns the string for sorted `str`
- In Python, `list(hash.values())` gives you the list of values

