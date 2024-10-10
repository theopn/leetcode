# 104. Maximum Depth of Binary Tree

## Relevant Skills

- Recursive DFS
- Iterative DFS using stack
- Iterative BFS using queue

## Approach

Recursive DFS, postorder (LRN)

0. If the node is root, return 0
0. Recursively call the self in the left node
0. Recursively call the self in the right node
0. Return bigger of two values + 1

Iterative DFS:

Iterative BFS:

0. Initialize depth variable, check for the 0 depth condition (`root == nil`)
0. Initialize a queue and enqueue root
0. Loop while queue is not empty
0. Increase a depth
0. Loop for the number of elements in the queue currently
0. Dequeue an element
0. Add left and right children to the queue if one exists
0. Return depth

## Optimization

## Pseudocode

Recursive DFS:

```lua
function max_depth(root)
    if root == nil then return 0 end
    left_val = max_depth(root.left)
    right_val = max_depth(root.right)
    return math.max(left_val, right_val)
end
```

Iterative BFS:

```lua
function max_depth(root)
    depth = 0
    if root == nil then return depth end

    q = {}
    q.enqueue(root)

    while not q.empty() do
        depth += 1

        num_q = q.n
        for i = 0, num_q - 1 do
            curr = q.dequeue()
            if curr.left then q.enqueue(curr.left) end
            if curr.right then q.enqueue(curr.right) end
        end
    end

    return depth
end
```

## Analysis

Whether it's in DFS or BFS, we are visiting every nodes, so $O(n)$

## Relevant Coding Skills

- In Python, don't forget `self.function_name` when making a recursive call using a class method
- In C++ `std::queue`:
    - `q.push(item);`: Enqueue
    - `temp = q.front(); q.pop();`: Dequeue
    - `q.empty()`: Check for an empty queue

