# 215. Kth Largest Element in an Array

## Relevant Skills

- Min-heap
- QuickSelect algorithm
- Array sorting

## Approach

Min-heap:

0. Initialize a min-heap
0. Iterate through the `num` in `nums`
0. Push `num`
0. If the size of the min-heap exceeds `k`, pop an element
0. Return the element with the highest priority out of the loop

QuickSelect:

0. Suppose we have the array `[6 5 2 1 4 3 4]`
0. Randomly choose a pivot `nums[rand() % nums.len]`. Let's say we got 4 as our pivot
0. Relative to the pivot, determine left, mid, and right array
    `left = [ 2 1 3 ]`, `mid = [4 4]`, `right = [6 5]`
    (We can do this in-place by swapping elements and keeping the index of `mid`, but it was too slow for some reason)
0. Forget about finding the kth largest, we are finding (n - k)th smallest.
    So if we are finding the 4th largest, we are in fact finding 7 - 4 = 3rd smallest
    (e.g., in `[1 2 3 4]`, 3 is the 2nd largest and 4 - 2 + 1 = 3rd smallest. But because of zero-indexing, we consider it to be 2nd smallest with 1 being the 0th smallest element).
0. Let's say we are finding the 5th smallest (4). 3 elements in the `left`, 2 elements in the `mid`, so it has to be in the `mid` (i.e., pivot value).

    What about finding 0nd smallest (1)? Since the length of `left` is 3 and it only contains values smaller than the pivot, call `QuickSelect` on the `left` to find its 2nd smallest.

    What about finding 6th smallest (5)? Call `QuickSelect` on the right to find the 6th smallest... No! Find the 1st smallest in the `right`, where `1 = 6 - left.len - mid.len`.

Array sorting:

0. Sort the array
0. Return `nums[nums.n - k]`

## Optimization

## Pseudocode

Min-heap:

```lua
function find_kth_largest(nums)
    min_heap = {}
    for num in nums do
        min_heap.push(num)
        if min_heap.n > k then min_heap.pop() end
    end
    return min_heap.peek()
end
```
QuickSelect:

```lua
function find_kth_largest(nums)
    local quick_select = function()
        -- Choose a random pivot
        pivot = math.random(nums)
        -- Roughly sort the array by determining its position relative to the pivot
        left = mid = right = []
        for num in nums do
            if num == pivot then mid.insert(num)
            elseif num < pivot then left.insert(num)
            else right.insert(num)
            end
        end

        if left.n <= k < left.n + mid.n then
        -- Base case: (n - k)th element is in the mid array, i.e. it's the pivot
            return mid[0] --> or return pivot
        elseif k < left.n then
        -- Case: kth largest element is in the left array, i.e. smaller than the pivot
            return quick_select(left, k)
        else
            return quick_select(right, k - left.n - mid.n)
        end
    end

    -- Instead of finding the kth largest elem, find (n - k)th smallest element
    return quick_select(nums, nums.n - k)
end
```

Array sorting:

```lua
function find_kth_largest(nums)
    table.sort(nums)
    return nums[nums.n - k]
end
```

## Analysis

- Min-heap is $O(n)$ with space complexity of $O(n)$
- QuickSelect is average $O(n)$ with worst case $O(n^{2})$
- Sorting takes $O(n \log (n))$

## Relevant Coding Skills

- In C++, `priority_queue` is max-heap. So instead of pushing `num`, push `-1 * num`, and instead of `return heap.pop()`, `return -heap.pop()`

