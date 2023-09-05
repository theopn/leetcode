# 2. Add Two Numbers [Medium]

## Relevant Skills

- Linked List traversal
- Linked List initialization to return

## Approach

0. Initialize carry at 0
0. Initialize a Linked List to hold our answers. In here, initialize the head with a dummy value and save the head. Why? Look at the following example
    ```lua
    bad_ans = nil
    bad_ans_ptr = ans
    good_ans = { val = "dummy value", next = nil }
    good_ans_ptr = good_ans

    while l1 and l2 do
        sum = 420 --> + some calculation
        -- ...
        bad_ans.next = { val = sum, next = nil }
        bad_ans = ans.next
    end

    -- good_ans_ptr == "dummy value", good_nas_ptr.next == 420, bad_nas_ptr == nil, bad_ans_ptr.next == nightmare
    return good_ans_ptr.next, bad_ans_ptr.next
    ```
0. While both `l1` and `l2` are not nil, calculate sum using `sum = l1.val + l2.val + carry`
0. Always calculate carry using `carry = sum / 10`
0. If sum is greater than 10, `sum = sum % 10`
0. Assign sum to the next node of the answer linked list
0. Repeat the whole while loop, but only for `l1` since it might have more digits than `l2`
0. Repeat the whole while loop, but only for `l2` since it might have more digits than `l1`
0. If carry exists after all the calculation, assign it to the answer linked list

## Optimization

- Always calculate `sum = sum % 10` since if it's smaller than 10, it will have no effect.

## Pseudocode

```lua
function add_two_num(l1, l2)
    int carry = 0
    -- Dummy val prevents ans_bak to be nil and actually follow the ans linked list
    ans = { val = "dummy value", next = nil }
    ans_bak = ans

    while l1 and l2 do
        -- Calculation
        sum = l1.val + l2.val + carry
        carry = sum / 10
        sum = sum % 10

        -- Assignment and moving on to the next node
        ans.next = { val = sum, next = nil }
        l1, l2, ans = l1.next, l2.next, ans.next
    end
    while l1 do
        sum = l2.val + carry
        carry = sum / 10
        sum = sum % 10
        ans.next = { val = sum, next = nil }
        l1, ans = l1.next, ans.next
    end
    while l2 do
        sum = l2.val + carry
        carry = sum / 10
        sum = sum % 10
        ans.next = { val = sum, next = nil }
        l2, ans = l2.next, ans.next
    end

    if carry != 0 then
        ans.next = { val = carry, next = nil }
    end

    return ans_bak.next --> de facto had of the list after the dummy val
end
```

## Analysis

- Let $n$ be the length of `l1` and $m$ be the length of `l2`
- The first while loop is $O(n)$ or $O(m)$, whichever is larger
- The second while loop is $O(n)$
- The third while loop is $O(m)$
- Thus, the whole while loop depends on whichever list is larger.
    We don't know that, but we know for sure that it is smaller than $n + m$.
    Thus, the run time is $O(n + m)$.

## Relevant Coding Skills

