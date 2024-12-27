class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long chalkSum = 0;
        for (auto ch : chalk) {
            chalkSum += ch;
        }

        // Subtract the sum of chalk from k until k is less than the sum of chalk.
        k %= chalkSum;

        // Now iterate over the array. If chalk[i] is less than k, this is the answer. Otherwise, subtract chalk[i] from k and continue.
        for (int i = 0; i < chalk.size(); i++) {
            if (chalk[i] > k) return i;
            k -= chalk[i];
        }

        return chalk.size() - 1;
    }
};