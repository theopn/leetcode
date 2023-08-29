class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i <= j) {
            if (!isalnum(s[i])) { i++; }
            else if (!isalnum(s[j])) { j--; }
            else if (tolower(s[i]) != tolower(s[j])) { return false; }
            else { i++; j--; } // You can do i++ j-- in the else if above, but it's slower
        }
        return true;
    }
};
