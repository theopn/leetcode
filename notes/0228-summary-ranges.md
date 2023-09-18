# 228. Summary Ranges

## Relevant Skills

- String appending

## Approach

0. Iterate through indices in `nums.n`
0. Save `nums[i]` as `head`
0. Advance `i` while the `i + 1` is consecutive
0. Format the string (`head` or `head`->`nums[i]`)

## Optimization

## Pseudocode

```lua
function summary_range(nums)
    ans = []
    for i = 0, nums.n - 1 do
        head = nums[i]

        while i + 1 < nums.n and
              nums[i + 1] = nums[i] + 1
        do
            i += 1
        end

        if head == nums[i] then
            res = head
        else
            res = head .. "->" .. nums[i]
        end
        ans.insert(res)
    end
    return res
end
```

## Analysis

- $O(n)$, even though there is a nested loop, because it changes `i`, every elements will be visited exactly once

## Relevant Coding Skills

- In C++, use `std::to_string(val)` to covert an integer `val` to a string

