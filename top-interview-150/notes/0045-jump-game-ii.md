# Jump Game II

## Relevant Skills

- Two Pointers
- DP

## Approach

0. Initialize DP array of size `nums.n - 1` with `DP[0] = nums[0]`
0. For each element, calculate the maximum length it can reach
    - Let `nums = [2 3 1 1 4]`, `DP = [2]`
    - At `i = 1`, we can go `1 + nums[1] == 1 + 3 == 4`; `DP = [2 4]`
    - At `i = 2`, we can go `2 + nums[2] == 2 + 1 == 3`.
        But wait, at `i = 2`, we would just better off jumping 4 in the previous index than travelling to `i = 2` at all
        So just make it 4; `DP = [2 4 4]`
    - Repeat the process, and we get `DP = [2 4 4 4]`
0. In a separate loop, keep track of the current index and number of jumps made until we reach the last index

## Optimization

- We can directly modify `nums` array instead of defining `dp`, but I will go ahead and define it anyway

## Pseudocode

```lua
function jump(nums)
    dp = [ nums[0] ]
    for i = 1, nums.n - 2 do
        dp.insert(max(i + nums[i], dp[i - 1]))
    end

    jumps = 0
    i = 0
    while i <= nums.n - 1 do
        jumps++
        i = dp[i]
    end

    return jumps
end
```

## Analysis

- $O(n)$, extra space $O(n)$

## Relevant Coding Skills

- In C++, `.size()` of vector returns unsigned integer
    ```cpp
    while (i < nums.size() - 2) { // if array length is 1, this loop will never end!
        // ...
    }
    ```
    So just use `i <= nums.size() - 1`

