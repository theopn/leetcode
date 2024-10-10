# 238. Product of Array Except Self

## Relevant Skills

- Prefix sum

## Approach

0. Make a prefix product array (`pre[i - 1] * nums[i - 1]`)
0. Make a suffix product array (`suf[i + 1] * nums[i + 1]`)
0. Make an answer array (`pre[i] * suf[i]`)

Example:

```
nums = [1 2 4 9 8]

// pre[0] is initialized to 1
         0(1)        1(2)     2(4)    3(9)        4(8)
pre = [ 1            1*1     1*1*2   1*1*2*4    1*1*2*4*9 ]
   == [ 1             1        2        8           72    ]

// suf[n - 1] is initialized to 1
suf = [ 1*8*9*4*2  1*8*9*4   1*8*9    1*8          1      ]
   == [   576        288       72      8           1      ]

ans = [ 1*576        1*288     2*72    8*8         72*1   ]
   == [ 576           288       144     64          72    ]
```

## Optimization

- There is no need to make three array, just use `pre` or `suf` array as `ans`

## Pseudocode

```lua
function product_except_self(nums)
    pre_and_ans[0] = [1]
    suf[nums.n - 1] = [1]

    for i = 1, nums.n - 1 do
        pre_and_ans[i] = pre_and_ans[i - 1] * nums[i - 1]
    end

    for i = nums.n - 2, 1, -1 do
        suf[i] = suf[i + 1] * nums[i + 1]
    end

    for i = 0, nums.n - 1 do
        pre_and_ans[i] = pre_and_ans[i] * suf[i]
    end
    return pre_and_ans
end
```

## Analysis

- $O(n)$

## Relevant Coding Skills

