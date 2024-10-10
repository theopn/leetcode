# 202. Happy Number

## Relevant Skills

- Hashmap
- Floyd's tortoise and hare algorithm

## Approach

Main idea is that if the number is not happy, `n` will be repeated after calculating the sum of squares of digits sometime.

Hashmap approach:

0. Define a hashmap
0. Loop while n is not equal to 1
0. If the current `n` is found in the hashmap, return false
0. Else, add `n` to the hashmap
0. Modify `n` to be the sum of squares of its digits

Tortoise and Hare approach:

0. Define a subroutine that calculates the sum of squares of digits
0. Initialize slow (tortoise) and fast (hare) pointers
0. While they are not equal to each other, calculate next number using the subroutine, but for the hare, calculate it twice
0. Out of the loop, if they are 1, return true
0. Else false

There are other mathematical properties that can help solve this problem.
Reference [Happy Number Wikipedia](https://en.wikipedia.org/wiki/Happy_number).

## Optimization

## Pseudocode

Hashmap:

```lua
function is_happy(n)
    hash = {}
    while n != 1 do
        if n in hash then return false
        else hash[n] = 69
        end

        sum = 0
        while sum > 0 do
            sum += (n % 10)^2
            n /= 10
        end
        n = sum
    end

    return true
end
```

Tortoise and Hare:

```lua
function is_happy(n)
    calc = function(n)
        sum = 0
        while n > 0 do
            sum += (n % 10)^2
            n /= 10
        end
        return sum
    end

    tortoise = hare = n
    repeat
        tortoise = calc(tortoise)
        hare = calc(calc(tortoise))
    until(tortoise != hare)

    return tortoise == 1
end
```

## Analysis

- It's hard to analyze this (same runtime for both btw). If you are in the interview, just say some BS like
    > So assuming the hashmap is optimized to run in the $O(1)$ average time, the runtime depends on the input number `n`
    > and steps it takes to reach the same number after calculating the sum of squares of digits.
    > I would say the runtime is $O(kd)$ where
    > $k$ is the time it takes to see the same number
    > and $d$ is the maximum number of digits we reach while we are iterating.
    > And yes, I just said what everyone knows without giving you the actual runtime.
    > But I'm not a math major so I'm not sure.

## Relevant Coding Skills

- `sum([int(digit) ** 2 for digit in str(n)])`: Calculating sum of squares in Python

