# 101. Symmetric Tree 

## Relevant Skills

- Recursive DFS

## Approach

0. Check if value of left and right are the same (after checking they both exists)
0. Return `is_sym(left.left, right,right) and is_sym(left.right, right.left)`
0. Since we need to check if the root is NULL, make the above process a helper

## Optimization

## Pseudocode

```lua
function is_sym(root)
    local helper = function(left, right)
        if not left and not right then return true end
        if (not left or not right) or (left.val ~= right.val) then
            return false
        end
        return helper(left.left, right.right) and helper(left.right, right.left)
    end

    return root ~= nil and helper(left, right) or true --> if root is nil, return true
end
```

## Analysis

- $O(n)$ because it visits every node in the worst case scenario

## Relevant Coding Skills

