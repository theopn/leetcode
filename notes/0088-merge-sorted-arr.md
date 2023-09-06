# 88. Merge Sorted Array

## Relevant Skills

- `Merge` algorithm from `MergeSort`

## Approach

It's like `Merge` algorithm (climbing the ladder), but because we are to store elements in `nums1` array in-place, compare from the larger to smaller items.

0. Assign pointers `i` and `j` to the end of each array
0. Loop while `i` and `j` is greater than 0
0. Calculate the index of the current element by `i + j + 1`
0. Assign bigger one of `nums1[i]` or `nums2[j]` to the `nums1[index]`
0. Decrement pointer of whatever was assigned
0. If `j` isn't 0, assign rest of the elements in `nums2` to `nums1`

Example 1:

```
nums1 = [1 2 4 0 0 0]
nums2 = [3 5 6]
i = 2, j = 2
->
nums1 = [1 2 | 3 4 5 6]
nums2 = [~3~ ~5~ ~6~]
i = 1, j = -1
```

Even though we `i` is greater than 1, we don't need to take any action since `nums1` is already sorted

Example 2:

```
nums1 = [3 4 0 0 0]
nums2 = [1 2 5]
i = 1, j = 2
->
nums1 = [~3~ ~4~ | 3 4 5]
nums2 = [1 2 ~5~]
i = -1 j = 1
```

If we have a "leftover" `j`, we need to spend it all so that we can finish `nums1`

```
nums1 = [1 2 3 4 5]
nums2 = [~1~ ~2~ ~5~]
i = -1 j = -1
```

## Optimization

## Pseudocode

```lua
function merge(nums1, m, nums2, n)
    i, j = m - 1, n - 1

    while i >= 0 and j >= 0 do
        index = i + j + 1
        if nums1[i] > nums2[j] then
            nums1[index] = nums1[i]
            i -= 1
        else
            nums1[index] = nums2[j]
            j -= 1
        end
    end

    -- Taking care of leftover j
    while j >= 0 do
        nums1[index] = nums2[j]
        j -= 1
    end
end
```

## Analysis

- Main loop is $O(n + m)$, strictly $O(max(n, m))$

## Relevant Coding Skills


