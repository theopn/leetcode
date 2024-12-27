class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        for i, num in enumerate(nums):
            nums[i] = str(num)

        def merge(l, r):
            res = []
            i = j = 0

            while i < len(l) and j < len(r):
                # because a..b > b..a and b..c > c..b then a..c > c..a (transitivity),
                #   if l[i]..r[j] > r[j]..l[i], then l[i] should come before r[j]
                if int(l[i] + r[j]) > int(r[j] + l[i]):
                    res.append(l[i])
                    i += 1
                else:
                    res.append(r[j])
                    j += 1
            
            res.extend(l[i:])
            res.extend(r[j:])

            return res

        def mergesort(arr):
            if len(arr) <= 1:
                return arr
            
            mid = len(arr) // 2
            left = arr[:mid]
            right = arr[mid:]

            lsorted = mergesort(left)
            rsorted = mergesort(right)
            return merge(lsorted, rsorted)

        nums = mergesort(nums)
        # if the first (largest) element is 0, it means rest are also 0 and should be discarded
        return "".join(nums) if int(nums[0]) != 0 else "0"
        