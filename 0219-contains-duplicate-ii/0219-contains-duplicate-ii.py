class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        hashbrown = {} # Maps nums[i] to i

        for i in range(len(nums)):
            curr = nums[i]
            if curr in hashbrown:
                if i - hashbrown[curr] <= k:
                    return True
            hashbrown[curr] = i
    
        return False