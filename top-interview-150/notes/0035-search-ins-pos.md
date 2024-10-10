# 35. Search Insert Position

## Relevant Skills

- Binary search

## Approach

0. Perform binary search
0. Out of the loop, return `low` (regular binary search would return -1 indicating that the element was not found).
    Why? Consider `nums = [2 4 5 6 7]` and `target = 3`.

    ```
      target = 3
      [2 4 5 6 7]
       | |
       r l

      target = 1
      [2 4 5 6 7]
     | |
     r l

      target = 8
      [2 4 5 6 7]
               | |
               r l
    ```

    Low pointer always points the element bigger than the `target` due to `l <= r` condition.

## Optimization

## Pseudocode

```lua
function search_ins(nums, target)
    l, r = 0, nums.n - 1

    while l <= r do
        m = l + (r - l) / 2
        if nums[m] == target then return m end

        if nums[m] < target then --> Ignore left portion
            l = m + 1
        else                     --> Ignore right portion
            r = m - 1
        end
    end

    -- Regular binary search would return -1 indicating the element was not present in the arr
    return l
end
```

## Analysis

- $O(\log n)$

## Relevant Coding Skills

