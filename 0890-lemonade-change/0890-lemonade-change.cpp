class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int numFive = 0;
        int numTen = 0;

        for (auto bill : bills) {
            if (bill == 5) {
                // No change required
                numFive++;
                continue;
            } else if (bill == 10) {
                // 5 required
                if (numFive == 0) return false;

                numFive--;
                numTen++;
            } else { // bill == 20
                // 10+5 or 5+5+5+, check 10+5 first
                if (numFive >= 1 && numTen >= 1) {
                    numFive--;
                    numTen--;
                } else if (numFive >= 3) {
                    numFive -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};