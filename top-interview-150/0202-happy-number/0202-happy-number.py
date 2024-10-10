class Solution:
    def isHappy(self, n: int) -> bool:
        def calc_sum_squares(n):
            return sum([int(digit) ** 2 for digit in str(n)])

        tortoise = calc_sum_squares(n)
        hare = calc_sum_squares(calc_sum_squares(n))
        while tortoise != hare:
            tortoise = calc_sum_squares(tortoise)
            hare = calc_sum_squares(calc_sum_squares(hare))
            
        return hare == 1
        