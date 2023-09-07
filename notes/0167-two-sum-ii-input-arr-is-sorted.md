# 167. Two Sum II - Input Array Is Sorted

## Relevant Skills

- Two Pointers

## Approach

0. Keep pointers for the beginning and end of the array
0. Loop condition hardly matters, since the problem states that there always is a solution
0. Take the sum of elements that the pointers are pointing
0. If it's the same as the target, return
0. If it's bigger than the target, we need to reduce to the smaller element, i.e., decrement the end pointer
0. If it's smaller than the target, we need to increase to the larger element, i.e., increment the beginning pointer

## Optimization

## Pseudocode

```lua
function two_sum(nums, target)
    front, end = 0, nums.n - 1

    while front < end do --> can be while true
        sum = nums[front] + nums[end]

        if sum == target then
            return [front + 1, end + 1]
        elseif sum > target then
            end -= 1
        else
            front++
        end
    end

    return [-1, -1] --> Shouldn't happen due to the question condition that there always is one solution
end
```

## Analysis

- Worst case, either `front` or `end` pointer will travel until it meets the other.
    Thus, $O(n)$

## Relevant Coding Skills

