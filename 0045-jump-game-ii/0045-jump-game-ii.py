class Solution:
    def jump(self, nums: List[int]) -> int:
        dp = []
        dp.append(nums[0])
        for i in range(1, len(nums)):
            dp.append(max(i + nums[i], dp[i - 1]))

        jumps = 0
        idx = 0
        while idx <= len(nums) - 2:
            jumps += 1
            idx = dp[idx]

        return jumps