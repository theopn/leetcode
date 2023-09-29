# 80. Remove Duplicates from Sorted Array II

## Relevant Skills

- Remove dup template

## Approach

Use the following template for "removing duplicates repeated more than $n$ times"

```lua
function remove_dup(nums, n)
    if nums.n <= n then return nums.n end

    pos = n
    for i = n, nums.n - 1 do
        if nums[i] ~= nums[pos - n] then
            nums[pos] = nums[i]
            pos++
        end
    end
    return pos
end
```

## Optimization

## Pseudocode

```lua
function remove_dup(nums)
    if nums.n <= 2 then
        return nums.n
    end

    pos = 2
    for i = 2, nums.n - 1 do
        if nums[i] ~= nums[pos - 2] then
            nums[pos] = nums[i]
            pos++
        end
    end
    return pos
end
```

## Analysis

- $O(n)$

## Relevant Coding Skills

