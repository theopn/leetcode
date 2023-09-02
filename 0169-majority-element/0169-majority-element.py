class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        m, i = -1, 0
        for num in nums:
            if i == 0:
                m = num
                i = 1
            elif m == num:
                i += 1
            else:
                i -= 1
                
        return m