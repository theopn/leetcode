# 55. Jump Game [Medium]

## Relevant Skills

- Two Pointers

## Approach

0. Initialize the current index pointer at the very end of the array
0. From the end of the array, check if `curr` can be approached by `i` + jump length at `i` (i.e., `i + nums[i] >= curr`)
    - `[2 3 |0| |1| 4]` if `i = 2` and `curr = 3`, you cannot approach `curr` since `nums[i] + i = 0 + 2 < 3`
    - `[2 |3| 0 |1| 4]` we moved onto `i = 1` and `curr = 3`, and since `nums[i] + i = 3 + 1 >= 3`, we set `curr = i = 1`
    - `[|2| |3| 0 1 4]` repeat the process above.
        Since you can jump to `i = 1` with the jump length of 2, set `curr = 0`
0. In the end, check if `curr == 0`.
    If so, it means you can reach the beginning of the array from the back using the jump length, and the reverse holds true.

## Optimization

- Instead of starting the loop from the very back, start from the `nums.n - 2`, since `nums.n - 1` can be reached by not moving at all

## Pseudocode

```lua
function can_jump(nums)
    curr = nums.n - 1

    for i = nums.n - 2, 0, -1 do
        if i + nums[i] >= curr then
            curr = i
        end
    end

    return curr == 0
end
```

## Analysis

- $O(n)$ where $n$ is the length of `nums`

## Relevant Coding Skills

None.

