class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        
        n = len(nums)
        for i in range(n):
            j = i + 1
            k = n - 1
            
            while j < k:
                su = nums[i] + nums[j] + nums[k]
                
                if su < 0:
                    j += 1
                elif su > 0:
                    k -= 1
                else:
                    ans.append([nums[i], nums[j], nums[k]])
                    j += 1
                    k -= 1
                    
        real_ans = []
        [real_ans.append(x) for x in ans if x not in real_ans]
        return real_ans