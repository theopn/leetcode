# 226. Invert Binary Tree

## Relevant Skills

- Recursive DFS
- Iterative BFS

## Approach

DFS:

0. if current node is nil, return nil
0. Call self in left
0. Call self in right
0. Swap left and right node
0. return root

## Optimization

## Pseudocode

DFS:

```lua
function invert_tree(root)
    if root == nil then return nil end

    invert_tree(root.left)
    invert_tree(root.right)

    root.left, root.right = root.right, root.left
    return root
end
```

## Analysis

- Recursive: It visits every node, $O(n)$

## Relevant Coding Skills

