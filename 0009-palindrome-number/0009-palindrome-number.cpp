class Solution {
public:
    bool isPalindrome(int x) {
        // False if x is negative or positive ending with zero
        if ((x < 0) || (x != 0) && (x % 10 == 0)) return false;
        
        int reverse = 0;
        // Iterate through half the digits of x
        while (x > reverse) {
            // Move the current digits in the reverse by one place, add last digit of x
            reverse = (reverse * 10) + (x % 10);
            x /= 10; // Truncate the last digit of x
        }
        // x == rev for even length palindrom num, x == rev / 10 for odd length palindrom num
        return ((x == reverse) || (x == reverse / 10));
    }
};