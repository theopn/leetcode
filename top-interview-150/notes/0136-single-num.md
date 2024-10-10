# 136. Single Number

## Relevant Skills

- XOR

## Approach

Here's the truth table for XOR:

| A | B | $A \oplus B$ |
| - | - | ----- |
| F | F |   F   |
| F | T |   T   |
| T | F |   T   |
| T | T |   F   |

So $n \oplus n = 0$, and $n \oplus 0 = n$.
XOR is also commutative and associative.

For example, if `nums = [4,1,2,1,2]`,

$$
res = 4 \oplus 1 \oplus 2 \oplus 1 \oplus 2 \\
= 4 \oplus 1 \oplus 1 \oplus 2 \oplus 2 \tag{associativity} \\
= 4 \oplus (1 \oplus 1) \oplus (2 \oplus 2) \tag{commutativity}
- 4 \oplus 0 \oplus 0 \\
= 4
$$

## Optimization

## Pseudocode

```lua
function single_num(nums)
    res = 0
    for num in nums do
        res ~= num
    end
    return res
end
```

## Analysis

- $O(n)$

## Relevant Coding Skills

