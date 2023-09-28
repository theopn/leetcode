# 169. Majority Element

## Relevant Skills

- Hashmap
- Boyer-Moore majority vote algorithm

## Approach

Hashmap:

0. Initialize hashmap counter for all `num` in `nums`
0. Increment the counter as we iterate through `num`
0. If the element surpasses $\lfloor n / 2 \rfloor$, return `num`

Boyer-Moore majority vote algorithm:

- Initialize an element $m$ and a counter $i$ with $i = 0$
- For each element $x$ of the input sequence:
    - If $i = 0$, then assign $m = x$ and $i = 1$
    - else if $m = x$, then assign $i = i + 1$
    - else assign $i = i - 1$
- Return $m$

## Optimization

## Pseudocode

```lua
function majority_elem(nums)
    target = nums.n / 2
    counter = {}
    for num in nums do
        counter[num] = counter[num] + 1
        if counter[num] > target then return num end
    end
    return - 1
end
```

Boyer-Moore majority vote algorithm:

```lua
function majority_elem(nums)
    m, i = -1, 0

    for num in nums do
        if i == 0 then
            m = num
            i = 1
        elseif m == num then
            i += 1
        else
            i -= 1
        end
    end

    return m
end
```

## Analysis

- $O(n)$ iteration for hashmap, $O(n^{2})$ worst case with hashmap chaining
- $O(n)$ for Boyer-Moore

## Relevant Coding Skills

