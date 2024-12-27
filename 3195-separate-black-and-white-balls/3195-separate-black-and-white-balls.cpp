class Solution {
public:
    long long minimumSteps(string s) {
        int whiteIdx = 0;
        long long swaps = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                swaps += i - whiteIdx;
                whiteIdx++;
            }
        }
        return swaps;
    }
};