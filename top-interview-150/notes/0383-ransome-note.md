# 383. Ransome Note

## Relevant Skills

- Hashmap

## Approach

Create a hashmap with number occurrence of characters in the `magazine`.
Iterate through the `random_note` and return false if we encounter a character with zero occurrence (for non-zero occurrence, decrement).

## Optimization

## Pseudocode

```lua
function can_construct(random_note, magazine)
    hash = {}
    for c in magazine do
        hash[c] = hash[c] and hash[c] + 1 or 1
    end
    for c in random_note do
        if hash[c] == 0 then return false end
        hash[c] -= 1
    end
    return true
end
```

## Analysis

$O(n)$ where $n$ is the length of magazine.
Space is also $O(n)$

## Relevant Coding Skills

- C++: `std::unordered_map` is a hashmap, `std::map` is a self-balancing BST ($O(\log (n))$ for most operations)
    - Default value of map is 0, meaning if you do `hash[c]++` and key `c` did not exist, it will be treated as 0 (`hash[c]` now equals to 1)
- Python: use `dict.get(key, default_val)` if dictionary has not been initialized
    - Alternatively, you can use `Counter`
- Java; Use `HashMap<Character, Integer>`


