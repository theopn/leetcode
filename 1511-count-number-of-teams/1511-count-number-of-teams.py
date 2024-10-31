class Solution:
    def numTeams(self, rating: List[int]) -> int:
        total = 0
        n = len(rating)

        for j in range(n):
            # Find the element smaller/greater than rating[j] in the left subarray
            left_smaller_than_j = 0
            left_greater_than_j = 0
            for i in range(0, j):
                if rating[i] < rating[j]:
                    left_smaller_than_j += 1
            # Find the element smaller/greater than rating[j] in the right subarray
            right_smaller_than_j = 0
            right_greater_than_j = 0
            for k in range(j + 1, n):
                if rating[k] > rating[j]:
                    right_greater_than_j += 1

            # Permutation of strictly increasing subsequence when rating[j] is the middle element
            total += left_smaller_than_j * right_greater_than_j


            # Permutation of strictly decreasing subsequence when rating[j] is the middle element
            # Because every elements are unique, we can calculate them w/o extra loop
            left_greater_than_j = j - left_smaller_than_j
            right_smaller_than_j = (n - 1 - j) - right_greater_than_j
            total += left_greater_than_j * right_smaller_than_j

        return total