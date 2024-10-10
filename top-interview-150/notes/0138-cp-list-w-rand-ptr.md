# 138. Copy List with Random Pointer

## Relevant Skills

- Hashmap

## Approach

0. Make a hashmap that stores original list node as a key and the corresponding copied node as the value
0. Complete this hashmap while making the copy of the list
0. Loop through the list again, this time assign the random pointer using the hashmap

## Optimization

## Pseudocode

```lua
function copy_rand_list(head)
    ans = { val = "dummy", next = nil, rand = nil }
    hash = {}

    -- Making backups
    ans_bak = ans
    head_bak = head

    -- Copy + hashmap init iteration
    while head do
        -- Make a copy
        ans.next = { val = head.val, nil, nil }
        ans = ans.next
        -- Assign hashmap
        hash[head] = ans
        -- Advance
        head = head.next
    end

    -- Restore
    head = head_bak
    ans = ans_bak.next --> bc the first node is a dummy

    -- Random assignment iteration
    while head do
        ans.rand = hash[head.rand]
        ans, head = ans.next, head.next
    end

    return ans_bak.next
end
```

## Analysis

Both loop are $O(n)$, so $O(2n) \in O(n)$

## Relevant Coding Skills

- In C++ initialize an unordered_map with `Node *` as the key and the value

