class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def quicksort(nums):
            n = len(nums)
            if n <= 1:
                return nums

            pivot = nums[random.randint(0, n - 1)]

            left = []
            for i in range(n):
                if nums[i] < pivot:
                    left.append(nums[i])

            mid = []
            for i in range(n):
                if nums[i] == pivot:
                    mid.append(nums[i])

            right = []
            for i in range(n):
                if nums[i] > pivot:
                    right.append(nums[i])

            return quicksort(left) + mid + quicksort(right)

        return quicksort(nums)
