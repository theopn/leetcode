# 27. Remove Element

## Relevant Skills

## Approach

0. Initialize index pointer at 0
0. Loop through `num` in `nums`
0. If `num` is not the excluded value `val`, assign it to `nums` at `k`
0. Increment `k`

## Optimization

## Pseudocode

```lua
function remove_elem(nums, val)
    k = 0
    for num in nums do
        if num ~= val then
            nums[k] = num
            k++
        end
    end
end
```

## Analysis

- $O(n)$

## Relevant Coding Skills

