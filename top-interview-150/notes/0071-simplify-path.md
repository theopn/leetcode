# 71. Simplify Path

## Relevant Skills

- Stack
- String split

## Approach

0. Split string along with "/"
0. Initialize a stack
0. If string is empty (double slash`foo//bar`) or `.` (`foo/./bar`), pass
0. if string is `..` and there's an element in the stack, pop the stack
0. For other elements, push it to the stack
0. Assemble a string based on the elements in the stack.
    - If stack is empty, return `/`
    - If not, **prepend** `/element` for every elements in the satck

## Optimization

- You can split strings on fly  z1

## Pseudocode

```lua
function simplify_path(path)
    splits = []
    for w in path:gmatch("%S+") do splits.insert(w) end

    stack = []
    for comp in splits do
        if comp == "" or comp == "." then
        elseif comp == ".." then
            if not stack.empty() then
                stack.pop()
        else
            stack.push()
        end
    end

    if stack.empty() then return '/' end

    res = ""
    while not stack.empty() do
        res = "/" + stack.pop() + res
    end

    return res
end
```

## Analysis

- $O(n)$, technically 3 iterations to split the string, iterate through elements, and empty the stack

## Relevant Coding Skills

