class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        n = len(nums)

        # sets the number of 1 as the size of the sliding window
        winSize = 0
        for num in nums:
            if num == 1:
                winSize += 1

        # Append the first winSize elements of the array to maintain the circular property
        nums.extend(nums[:winSize])

        # Count the zero's of the first subarray first
        zeroCount = 0
        for i in range(winSize):
            if nums[i] == 0:
                zeroCount += 1

        minZeroCount = zeroCount
        # while (head++) + winSize < len(newly updated nums)
        for head in range(n):
            #print(f"head: {head}")
            #print(f"tail: {head + winSize}")
            #print(f"Current window: {nums[head:head+winSize]}")
            #print(f"ZeroCount: {zeroCount}")
            #print(f"minZeroCount: {minZeroCount}")
            #print("-----")
            
            # Extend the tail of the window by one
            if nums[head + winSize] == 0:
                zeroCount += 1
            # Subtract the head of the window
            if nums[head] == 0:
                zeroCount -= 1
                
            # Update the minZeroCount
            minZeroCount = min(minZeroCount, zeroCount)

        return minZeroCount
