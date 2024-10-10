class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        front, end = 0, len(numbers) - 1
        
        while front < end:
            sum = numbers[front] + numbers[end]
            
            if sum == target:
                return [front + 1, end + 1]
            elif sum > target:
                end -= 1
            else:
                front += 1
                
        return [-1, -1]
        