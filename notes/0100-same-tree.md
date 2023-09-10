# 100. Same Tree

## Relevant Skills

- Tree traversal
- Recursion

## Approach

0. If both nodes are nil, return true
0. If only one of the nodes is nil, return false
0. If the values of nodes are different, return false
0. Return `recur(left nodes) and recur(right nodes)`

## Optimization

- Simplify checking only one of them being nil
    ```lua
    if p ~= nil and not q ~= nil then
        return false
    end
    if q ~= nil and not p ~= nil then
        return false
    end
    ```
    can be simplified to
    ```lua
    if not (p ~= nil and q ~= nil) then
        return false
    end
    ```
    assuming you checked `p == nil and q == nil` beforehand

## Pseudocode

```lua
function is_same_tree(p, q)
    if p == nil and q == nil then
        return true
    end
    if not (p ~= nil and q ~= nil) or (p.val ~= q.val) then
        return false
    end
    return is_same_tree(p.left, q.left) and is_same_tree(p.right, q.right)
end
```

## Analysis

- $O(min(H1, H2))$, where $H1$ and $H2$ are heights of each tree

## Relevant Coding Skills

- In Python, don't forget `self.function_name` when making a recursive call using a class method

