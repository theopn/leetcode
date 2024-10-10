# 209. Minimum Size Subarray Sum

## Relevant Skills

- Sliding window

## Approach

```
nums = [ 0 2 3 1 2 4 3], target = 7

t = 0:
    h = 0: [|2| 3 1 2 4 3]; curr_sum = 2; min_len = INF
    -> curr_sum < 7, no change to min_len

t = 1:
    h = 0: [|2 3| 1 2 4 3]; curr_sum = 5; min_len = INF
    -> curr_sum < 7, no change to min_len

t = 2:
    h = 0: [|2 3 1| 2 4 3]; curr_sum = 6; min_len = INF
    -> curr_sum < 7, no change to min_len

t = 3:
    h = 0: [|2 3 1 2| 4 3]; curr_sum = 8; min_len = INF
    -> curr_sum >= 7, min_len = max(INF, 4 - 0); h++ && curr_sum -= 2
    h = 1: [2 |3 1 2| 4 3]; curr_sum = 6; min_len = 4
    -> curr_sum < 7, no change to min_len

t = 4:
    h = 1: [2 |3 1 2 4| 3]; curr_sum = 9; min_len = 4
    -> curr_sum >= 7; min_len = max(4, 4); h++ && curr_sum -= 3
    h = 2: [2 3 |1 2 4| 3]; curr_sum = 6; min_len = 4
    -> curr_sum < 7, no change to min_len

t = 5:
    h = 2: [2 3 |1 2 4 3|]; curr_sum = 10; min_len = 4
    -> curr_sum >= 7; min_len = max(4, 4); h++ && curr_sum -= 1
    h = 3: [2 3 1 |2 4 3|]; curr_sum = 9; min_len = 3
    -> curr_sum >= 7; min_len = max(4, 3); h++ && curr_sum -= 2
    h = 4: [2 3 1 2 |4 3|]; curr_sum = 7; min_len = 2
    -> curr_sum >= 7; min_len = max(3, 2); h++ && curr_sum -= 4
    h = 4: [2 3 1 2 4 |3|]; curr_sum = 3; min_len = 1
    -> curr_sum < 7, no change to min_len

Therefore, the subarray [4, 3] with length of 2 is the answer
```

## Optimization

## Pseudocode

```lua
function min_subarr_len(target, nums)
    curr_sum = 0    --> 
    head = 0        --> Position of the window tail
    min_len = INF   -->

    for tail = 0, nums.n - 1 do
        curr_sum += nums[tail]

        while (curr_sum >= target) do
            curr_win_len = tail + 1 - head
            min_len = math.min(min_len, curr_win_len)

            curr_sum -= nums[head]
            head += 1
        end
    end

    return (min_len == INF) and 0 or min_len
end
```

## Analysis

$O(2n) \in O(n)$.

Think about `nums = [100 100 100 100 100], target = 1`.
In each iteration, `tail == head` because all individual element satisfy the `curr_sum >= target` condition, so it will iterate until `curr_sum` becomes 0.
So each element will be accessed exactly twice.

## Relevant Coding Skills

