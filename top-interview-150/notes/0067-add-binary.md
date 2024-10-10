# 67. Add Binary

## Relevant Skills

- Binary addition
- Casting

## Approach

## Optimization

## Pseudocode

```lua
funciton add_binary(a, b)
    ans = ""
    carry = 0
    a_pos = a.n - 1
    b_pos = b.n - 1

    while a_pos >= 0 or b_pos >= 0 do
        a_val = a_pos >= 0 and tonumber(a[a_pos]) or 0
        b_val = b_pos >= 0 and tonumber(b[b_pos]) or 0
        sum = a_val + b_val + carry

        if sum > 1 then
            sum = sum % 2
            carry = 1
        else
            carry = 0
        end

        ans = sum + ans
        a_pos -= 1
        p_pos -= 1
    end

    if carry then ans = '1' + ans end
    return ans
end
```

## Analysis

- $O(n + m)$ where $n$ and $m$ are length of a and b

## Relevant Coding Skills

- In C++:
    - `a[a_pos] - '0'` is an easy way to convert char to int
    - There is no easy way to prepend to the string.
        So append using `ans.append(to_string(sum))`, and reverse the string in the end using `std::reverse(ans.begin(), ans.end())`

