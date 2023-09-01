class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        sum, head_pos, min_len = 0, 0, len(nums) + 69
        
        for i in range(len(nums)):
            sum += nums[i]
            while sum >= target:
                if min_len > i + 1 - head_pos:
                    min_len = i + 1 - head_pos
                sum -= nums[head_pos]
                head_pos += 1
                
        return 0 if min_len == len(nums) + 69 else min_len