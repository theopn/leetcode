# 1. Two Sum

## Relevant Skills

- Hashmap

## Approach

0. Initialize a hashmap
0. Fill hashmap with `nums[i]` as a key and `i` as the value
0. Iterate through `num` in `nums`
0. Calculate complement, i.e. `target - num`
0. See if the complement exists in the hashmap we built
0. If it does, voila! We have the answer

## Optimization

- Instead of building a hashmap before the main loop, we can build hashmap as we execute the main loop
    ```lua
    hash = {}
    for i, num in ipairs(nums) do
        hash[num] = i
    end
    for i, num in ipairs(nums) do
        comp = target - num
        if comp in hash and hash[comp] != i then
            return {hash[comp] , i}
        end
    end
    ```

    versus

    ```lua
    hash = {}
    for i, num in ipairs(nums) do
        comp = target - num
        if comp in hash then --> notice we can skip another cond since hash[comp] will never be i
            return {hash[comp] , i}
        else
            hash[num] = i
        end
    end
    ```

    This will still be $O(n)$, but in cases like `nums = [1, 2, 3, 4, 5, ... 9999], target = 3`, instead of travelling the entire array to build a map, we travel two elements.
    In other words, it improves from $\Omega (n)$ to $\Omega (2) \in \Omega (1)$

## Pseudocode

```lua
function two_sum(nums, target)
    hash = {}
    for i, num in ipairs(nums) do
        comp = target - num
        if comp in hash then
            return [ hash[comp] , i ]
        else
            hash[num] = i
        end
    end
    return [ -1, -1 ]
end
```

## Analysis

- $O(n)$

## Relevant Coding Skills

