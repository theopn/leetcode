class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> seen;
        while (n != 1) {
            if (seen.count(n) > 0) {
                return false;
            }
            seen[n] = true;
            
            int sum = 0;
            while (n > 0) {
                sum += pow(n % 10, 2) ;
                n /= 10;
            }
            n = sum;
        }
        
        return true;
    }
};