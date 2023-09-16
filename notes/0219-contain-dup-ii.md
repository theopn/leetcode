# 219. Contains Duplicate II

## Relevant Skills

- Hashmap

## Approach

0. Make a hashmap that maps `num` in `nums` to index `i`
0. Iterate through the numbers
0. If we encounter a number not in the hash, add it to the hash
0. If we encounter one, check if the index is nearby (within target)
0. If yes, return true
0. Else, update the hash

## Optimization

## Pseudocode

```lua
function contain_nearby_dup(nums, k)
    hash = {}
    for i = 0, nums.n - 1 do
        curr = nums[i]
        if curr in hash then
            if i - hash[curr] <= k then return true end
        else
            hash[curr] = i
        end
    end

    return false
end
```

## Analysis

- $O(n)$

## Relevant Coding Skills

