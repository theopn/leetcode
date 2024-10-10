class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        pre_slash_ans, suf = [1] * n, [1] * n
        
        for i in range(1, n): # [1, n)
            pre_slash_ans[i] = pre_slash_ans[i - 1] * nums[i - 1]
        
        for i in range(n - 2, -1, -1): # (n - 1, 0]
            suf[i] = suf[i + 1] * nums[i + 1]

        for i in range(n):
            pre_slash_ans[i] = pre_slash_ans[i] * suf[i]

        return pre_slash_ans
