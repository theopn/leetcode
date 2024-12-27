class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorr = start ^ goal;
        
        int count = 0;
        while (xorr > 0) {
            count++;
            xorr = xorr & (xorr - 1);
        }
        return count;
    }
};