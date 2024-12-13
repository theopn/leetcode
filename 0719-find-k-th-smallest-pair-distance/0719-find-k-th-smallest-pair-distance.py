class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        n = len(nums)
        nums.sort()

        """
        Finds the number of pairs in nums where the diff. is smaller than mid
        Uses sliding window technique
        E.g., mid = 30
        [10, 20, 30, 40, 50]
          i               hi
        50 - 10 > 30, thus decrement hi
        [10, 20, 30, 40, 50]
          i          hi
        40 - 10 > 30, thus add hi - i to the count
        """
        def count_smaller(mid):
            smaller_than_mid = 0
            lo = 0
            for hi in range(n):
                while nums[hi] - nums[lo] > mid:
                    lo += 1
                smaller_than_mid += hi - lo
                
            return smaller_than_mid
                

        # Find the smallest difference
        #lo = nums[1] - nums[0]
        #for i in range(2, n):
        #    lo = min(lo, nums[i] - nums[i - 1])
        lo = 0  # 0 works and is faster

        # Find the largest difference
        hi = nums[n - 1] - nums[0]

        while lo < hi:
            mid = lo + ((hi - lo) // 2)  #(hi + lo) // 2

            count = count_smaller(mid)

            if count >= k:
                hi = mid
            else:
                lo = mid + 1
                
        return lo