class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        def reverse_quicksort(names, heights):
            n = len(names)
            if n <= 1:
                return names

            pivot = heights[n // 2]

            left_heights = []
            left_names = []
            for i in range(n):
                if heights[i] < pivot:
                    left_heights.append(heights[i])
                    left_names.append(names[i])

            mid_heights = []
            mid_names = []
            for i in range(n):
                if heights[i] == pivot:
                    mid_heights.append(heights[i])
                    mid_names.append(names[i])

            right_heights = []
            right_names = []
            for i in range(n):
                if heights[i] > pivot:
                    right_heights.append(heights[i])
                    right_names.append(names[i])

            return reverse_quicksort(right_names, right_heights) + mid_names + reverse_quicksort(left_names, left_heights)

        return reverse_quicksort(names, heights)
