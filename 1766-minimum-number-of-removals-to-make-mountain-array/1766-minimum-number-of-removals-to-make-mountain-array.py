class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        n = len(nums)

        # find longest increasing sequence ending at i
        lis = [1] * n
        for i in range(n):
            for j in range(i):
                if nums[j] < nums[i]:
                    lis[i] = max(lis[i], lis[j] + 1)

        # find longest decreasing sequence at starting at index i
        lds = [1] * n
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                if nums[j] < nums[i]:
                    lds[i] = max(lds[i], lds[j] + 1)

        # If there is a non-single lis and lds at i (i.e., a valid mountain peak), update the minremoval
        minremoval = float("inf")
        for i in range(n):
            if lis[i] > 1 and lds[i] > 1:
                minremoval = min(minremoval, n - lis[i] - lds[i] + 1)
        return minremoval