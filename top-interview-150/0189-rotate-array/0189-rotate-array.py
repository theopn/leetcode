class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        nums_cpy = nums.copy()
        
        for i in range(0, n):
            pos = (i + k) % n 
            nums[pos] = nums_cpy[i]
        