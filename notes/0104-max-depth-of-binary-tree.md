# 104. Maximum Depth of Binary Tree

## Relevant Skills

- Tree traversal
- Recursion

## Approach

0. If the node is root, return 0
0. Recursively call the self in the left node
0. Recursively call the self in the right node
0. Return bigger of two values + 1

## Optimization

## Pseudocode

```lua
function max_depth(root)
    if root == nil then return 0 end
    left_val = max_depth(root.left)
    right_val = max_depth(root.right)
    return math.max(left_val, right_val)
end
```

## Analysis

- We are travelling all nodes here, so $O(n)$ where $n$ is the number of nodes

## Relevant Coding Skills

- In Python, don't forget `self.function_name` when making a recursive call using a class method

