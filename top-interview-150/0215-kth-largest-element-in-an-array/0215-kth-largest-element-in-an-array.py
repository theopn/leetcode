class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def quickselect(nums, k):
            # Randomly choose a pivot value
            pivot = random.choice(nums) # pivot value
            
            # Roughtly "sort" the array by determining its position relative to the pivot
            left = [] # elements smaller than the pivot
            mid = [] # elements equal to the pivot
            right = [] # elements greater than the pivot
            for num in nums:
                if num == pivot:
                    mid.append(num)
                elif num < pivot:
                    left.append(num)
                else:
                    right.append(num)
             
            if len(left) <= k < len(left) + len(mid):
                # Base case: (n-k)th element is in the mid array, i.e., it's the pivot
                return mid[0] # or return pivot
            elif k < len(left):
                # Case: kth largest is in the left array (i.e., smaller than the pivot)
                return quickselect(left, k)
            else:
                # Case: kth largest is in the right array (i.e., greater than the pivot)
                return quickselect(right, k - len(left) - len(mid))
            
        # Instead of finding kth largest element, find (n - k)th smallest element
        return quickselect(nums, len(nums) - k)
                    