# 21. Merge Two Sorted Lists

## Relevant Skills

- `Merge` algorithm from `MergeSort`
- Dummy node for the return list

## Approach

0. Loop while both `list1` and `list2` pointers are valid
0. If `list1` value is smaller, assign that to the current answer list node and increment `list1`
0. If `list2` value is smaller, assign that to the current answer list node and increment `list2`
0. Advance `ans` linked list
0. Because of the while condition, one of `list1` or `list2` will not be fully advanced
0. Add whichever has leftover elements to the back of the list

## Optimization

- Since they are linked list, instead of looping through the leftover elements, just append the entire list 

## Pseudocode

```lua
function merge_two_lists(list1, list2)
    ans = { val = "Dummy", next = nil }
    ans_bak = ans

    while list1 and list2 do
        if list1.val < list2.val then
            ans.next = { val = list1.val, next = nil }
            list1 = list1.next
        else
            ans.next = { val = list2.val, next = nil }
            list2 = list2.next
        end

        ans = ans.next
    end

    if list1 then
        ans.next = list1
    elseif list2 then
        ans.next = list2
    end

    return ans_bak.next
end
```

## Analysis

- $O(n + m)$

## Relevant Coding Skills

