# 189. Rotate Array

## Relevant Skills

- Modulus
- Array reversal

## Approach

Modulus with copy of an array:

0. Make a copy of an array
0. Iterate the array and assign ith element to the `(i + k) % n` position

Array reversal:

For example, `arr = [ 1 2 3 4 5 6 7 ]` and `k = 3`

0. Reverse the entire array: `arr = [ 7 6 5 4 3 2 1 ]`
0. Separate the array into two parts, from 0 to `k - 1` and `k` to `arr.n - 1`: `arr = [ (7 6 5) (4 3 2 1) ]`
0. Rotate each of them: `arr = [ (5 6 7) (1 2 3 4) ]`
0. Before the step 1, don't forget to set `k = k % nums.n` in case k is greater than the length of the array

## Optimization

## Pseudocode

Modulus with copy of an array:

```lua
function rotate(nums, k)
    nums_cp = nums.copy()
    for i = 0, nums.n - 1 do
        nums[(i + k) % nums.n] = nums_cp[i]
    end
end
```

Array reversal:

```lua
function rotate(nums, k)
    k = k % nums.n
    reverse(nums, 0, nums.n)
    reverse(nums, 0, k)
    reverse(nums, k, nums.n)
end
```

## Analysis

- $O(n)$ for both runtime and space for making a copy
- The second method is $O(n)$ with $O(1)$ space complexity assuming that reversing an array takes $O(n)$

## Relevant Coding Skills

- With list slicing, you can use the following code in Python
    ```python
    def rotate(self, nums: List[int], k: int) -> None:
        k = k % len(nums)
        nums[:] = nums[-k:] + nums[:-k]
    ```

