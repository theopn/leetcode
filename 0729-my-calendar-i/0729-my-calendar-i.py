class MyCalendar:

    def __init__(self):
        self.events = []
        self.numEvents = 0

    def book(self, start: int, end: int) -> bool:
        # Run binary search with start values of existing events and the `end` parameter
        # to check end > booked_start
        lo = 0
        hi = len(self.events) - 1
        while lo <= hi:
            mid = lo + ((hi - lo) // 2)
            if self.events[mid][0] < end:
                lo = mid + 1
            else:
                hi = mid - 1
        startCandidate = lo

        # Run binary search with end values of existing events and the `start` parameter
        # to check start < booked_end
        # "<=" condition since the start time of the new event and the end time of existing event can overlap (basically using "bisect_right" instead of "bisect_left")
        lo = 0
        hi = len(self.events) - 1
        while lo <= hi:
            mid = lo + ((hi - lo) // 2)
            if self.events[mid][1] <= start:
                lo = mid + 1
            else:
                hi = mid - 1

        endCandidate = lo

        if startCandidate == endCandidate:
            self.events.insert(startCandidate, (start, end))
            return True

        return False


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)