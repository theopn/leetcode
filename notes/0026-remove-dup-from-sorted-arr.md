# 26. Remove Duplicates from Sorted Array

## Relevant Skills

## Approach

0. Initialize a pointer at index 1
0. Loop through `num` in `nums`
0. If `num` is different from `nums[p - 1]`, make `nums[p] == num` and increment `p`

## Optimization

Instead of looping the entire `num`, start at index 1

## Pseudocode

```lua
function remove_dup(nums)
    p = 1
    for i = 1, nums.n - 1 do
        if nums[i] ~= nums[p - 1] then
            nums[p] = nums[i]
            p++
        end
    end
end
```

## Analysis

- $O(n)$

## Relevant Coding Skills

