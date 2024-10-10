# 134. Gas Station

## Relevant Skills

- Greedy algorithm

## Approach

0. Loop through the `gas`
0. Initialize two variables: one that tracks the total amount of gas left in the current loop (`curr_gas`) and one that tracks the total amount of gas overall (`total_gas`)
0. The cost to move to the next gas station is calculated by `gas[i] - cost[i]`, add this to both variables
0. If we have negative gas in the current loop, it means wherever we started is not a good starting point.
    Reset the starting point to the one after and reset `curr_gas`
0. In the end of the loop, check if we have a non-negative `total_gas`.
    If we do, it means we can complete the circle: return the starting point we found
    Else, it means we cannot complete the circuit

## Optimization

## Pseudocode

```lua
function can_complete_circuit(gas, cost)
    curr_gas, total_gas, start = 0
    for i = 0, gas.n - 1 do
        curr_gas += gas[i] - cost[i]
        total_gas += gas[i] - cost[i]

        if curr_gas < 0 then
            start = i + 1
            curr_gas = 0
        end
    end
    return (total_gas >= 0) and start or -1
end
```

## Analysis

$O(n)$

## Relevant Coding Skills

