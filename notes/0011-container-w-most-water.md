# 11. Container With Most Water

## Relevant Skills

- Two Pointers

## Approach

0. Initialize two pointers in the beginning and the end of the array
0. Initialize current maximum
0. While the `left` pointer does not exceed `right`, iterate
0. Calculate the area.
    - The height is determined by the smaller of `height[left]` and `height[right]`
        ```
        3   |
        2   |---|
        1   |___|
        0 left  right

        height = 2, since right is the smaller one
        ```
    - The width is `right - left`
0. If the area is greater than the current maximum, update the maximum
0. Move smaller of `left` or `right`

## Optimization

## Pseudocode

```lua
function max_area(height)
    max_area = 0
    left, right = 0, height.n - 1

    while left < right do
        area = math.min(height[left], height[right]) * (right - left)

        if area > max_area then max_area area end

        if height[left] > height[right] then
            right -= 1
        else
            left += 1
        end
    end

    return max_area
end
```

## Analysis

- Worst case scenario, say, a strictly increasing, sorted array, `right` pointer will remain the same and `left` pointer will traverse n - 1 elements.
    Since the number of iteration is directly proportional to the number of elements in the array, the runtime is $O(n)$.

## Relevant Coding Skills

