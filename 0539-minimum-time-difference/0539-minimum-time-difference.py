class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        # 1. convert time points to minutes relative to midnight
        for i, timePoint in enumerate(timePoints):
            hour, minute = timePoint.split(":")
            timePoints[i] = int(hour) * 60 + int(minute)
            print(f"timepoints[{i}] = {timePoints[i]}")
        
        # 2. sort
        timePoints.sort()

        # 3. find the smallest time[i] - time[i - 1]
        smallestConsecutiveDiff = float("inf")
        for i in range(1, len(timePoints)):
            smallestConsecutiveDiff = min(smallestConsecutiveDiff, timePoints[i] - timePoints[i - 1])

        # 4. find the time[last] - time[0]
        # 4.1. 1440 - abs(a - b)
        circularDiff = 1440 - abs(timePoints[-1] - timePoints[0])  # 24 * 60 = 1440

        # 5. find the smallest of two
        return min(circularDiff, smallestConsecutiveDiff)