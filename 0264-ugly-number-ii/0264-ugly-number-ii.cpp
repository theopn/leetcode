class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNumbers(n);
        uglyNumbers[0] = 1;

        int ptrMultiple2 = 0;
        int ptrMultiple3 = 0;
        int ptrMultiple5 = 0;

        for (int i = 1; i < n; i++) {
            int candidateMultiple2 = uglyNumbers[ptrMultiple2] * 2;
            int candidateMultiple3 = uglyNumbers[ptrMultiple3] * 3;
            int candidateMultiple5 = uglyNumbers[ptrMultiple5] * 5;

            uglyNumbers[i] = min(candidateMultiple2, min(candidateMultiple3, candidateMultiple5));

            if (uglyNumbers[i] == candidateMultiple2) {
                ptrMultiple2++;
            }
            if (uglyNumbers[i] == candidateMultiple3) {
                ptrMultiple3++;
            }
            if (uglyNumbers[i] == candidateMultiple5) {
                ptrMultiple5++;
            }
        }

        return uglyNumbers[n - 1];
    }
};