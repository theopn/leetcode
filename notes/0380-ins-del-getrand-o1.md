# 380. Insert Delete GetRandom O(1)

## Relevant Skills

- OOP
- Random

## Approach

- Init: Initialize an array, a dictionary to map values to indices, and length of the array
- Insert: Check if the element exists in the array by checking the hash. If no duplicate is found, simply update all three fields
- Remove: To make it $O(1)...
    - Swap the last element and the element we are removing
    - Remove the (now) last element
- Random: Generate a random number smaller than the length of the array and return the element

## Optimization

In the removal, instead of swapping, we can just copy the last element to the index of the element to be removed.

For example:

- `[3 5 4]`, removing 5.
- Swap 4 and 5: `[3 4 5]`
- Remove 5 `[3 4]`

is no different than:

- `[3 5 4]`, removing 5.
- Copy 4 to 5's position: `[3 4 4]`
- Remove 4 `[3 4]`

## Pseudocode

```lua
RandomizedSet = {}

RandomizedSet:init = function()
    self.arr = {}
    self.hash = {}
    self.length = 0
end

RandomizedSet:insert(val) = function()
    if hash[val] == nil then
        self.arr[self.length] = val
        self.hash[val] = self.length
        self.length += 1
        return true
    end
    return false
end

RandomizedSet:remove(val) = function()
    if hash[val] ~= nil then
        elem_idx = self.hash[val]
        last_idx = self.length - 1
        -- Place last element in the index of the element to be removed
        self.arr[elem_idx] = self.arr[last_idx]
        -- Update the hashmap value for the former last element
        self.hash[last_idx] = self.hash[elem_idx]

        table.remove(self.arr, last_idx)
        self.length -= 1
        table.remove(self.hash, val)
        return true
    end
    return false
end

RandomizedSet:getRandom() = function()
    return self.arr[math.random(self.length)]
end
```

## Analysis

All $O(1)$?

## Relevant Coding Skills

In Python:
- Use `random.randint(lower, upper)` (both included) to generate a random number, or use `random.choice(arr)` to pick a random element from a list

