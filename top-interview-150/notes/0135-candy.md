# 135. Candy

## Relevant Skills

- Greedy algorithm

## Approach

0. Since everyone must get at least one candy, initialize `candies` array of size `raitings.n`
0. Loop from the front to back.
0. If the rating of the current child is higher than the i - 1 (left child), update the candies for the current child to be one greater than the previous
0. Loop from the back to front
0. If the rating of the current child is higher than the i + 1 (right child), update the candies for the current child to be one greater than the next IFF `candies[i + 1] + 1` is greater than what was calculated in the earlier loop
0. Return the sum of candies

## Optimization

## Pseudocode

```lua
function candy(ratings)
    candies = {}
    for i = 0, raitings.n - 1 do
        candies[i] = 1
    end

    -- Check if the current raiting is higher than the right
    for i = 1, raitings.n - 1 do
        if ratings[i] > ratings[i - 1] then
            candies[i] = candies[i - 1] + 1
        end
    end

    -- Check if the current raiting is higher than the left
    for i = n - 2, 0, -1 do
        if ratings[i] > ratings[i + 1] then
            -- Do not update if the candies value is smaller than what was calculated earlier!
            candies[i] = math.max(candies[i], candies[i + 1] + 1)
        end
    end

    return sum(candies)
end
```

## Analysis

$O(n^2) \in O(n)$

## Relevant Coding Skills

- Use `sum(arr)` in Python to add all elements in the array

