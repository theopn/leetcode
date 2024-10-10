# 9. Palindrome Number

## Relevant Skills

- Python one-liner

## Approach

0. If the number of negative or positive ending with 0 (e.g., 100), it's not a palindrome number
0. Initialize reverse of x with 0
0. Loop while x is greater than reverse
0. Move one digit to a reverse at a time, truncate a digit from x
0. If it's even length palindrome, (e.g., original x = 1221, modified x = 12, rev = 12), x and rev will be the same
0. if it's odd length palindrome, (e.g., original x = 12321, modified x = 12, rev = 123), discard the last digit of rev

- e.g.: 121
- 1st iter: x = 12321, reverse = 0 * 10 + 12321 % 10 = 1
- 2nd iter: x = 1232,  reverse = 1 * 10 + 1232 % 10 = 12
- 3rd iter: x = 123,   reverse = 12 * 10 + 123 % 10 = 123
- 4th iter: x = 12 -> loop terminates
- Since 12 == 123 / 10, it is a palindrome number

## Optimization

## Pseudocode

```lua
function is_palindrome(x)
    -- False if x is negative or positive ending with zero
    if x < 0 or (x != 0 and x % 10 == 0) then return false end

    reverse = 0
    -- Iterate through half the digits of x
    while x > reverse do
        -- Move the current digits in the reverse by one place, add last digit of x
        reverse = (reverse * 10) + (x % 10)
        x = x / 10 --> Truncate last digit of x
    end

    -- x == rev for even length palindrom num, x == rev / 10 for odd length palindrom num
    return ((x == reverse) or (x == reverse / 10));
end
```

## Analysis

- $O(\frac{n}{2}) \in O(n)$

## Relevant Coding Skills

