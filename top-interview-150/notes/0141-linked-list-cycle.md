# 141. Linked List Cycle

## Relevant Skills

- Floyd's tortoise and hare

## Approach

0. Initialize two pointers, `tortoise` and `hare`
0. Loop through linked list making sure not to invoke `nil.next`
0. Tortoise is a slow-paced pointer -- it only moves to the next node per iteration
0. Hare is a fast-paced pointer -- it moves two nodes per iteration
0. If they meet, we know that there is a cycle

## Optimization

- Instead of checking if `tortoise ~= nil and hare ~= nil and hare.next ~=nil`, I can omit `tortoise` nil check.
    If the linked list has no cycle (i.e., a pointer will eventually become nil), then hare would've become nil and loop would've terminated long before `tortoise` would have a chance to be nil

## Pseudocode

```lua
function has_cycle(head)
    tortoise, hare = head, head

    while hare ~= nil
          and hare.next ~= nil
    do
        tortoise = tortoise.next
        hare = hare.next.next

        if tortoise == hare then
            return true
        end
    end

    return false
end
```

## Analysis

- Algorithm has been proven to iterate exactly the length of the linked list.
    - Let the starting index be $\mu$ and the length of the list $\lambda$, the algorithm uses $O(\lambda + \mu)$ operations
- Yeah, $O(n)$

## Relevant Coding Skills

