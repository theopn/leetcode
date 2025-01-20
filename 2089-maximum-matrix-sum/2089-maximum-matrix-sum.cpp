class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long summ = 0;
        int minn = INT_MAX;
        int negcount = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                summ += abs(matrix[i][j]);
                if (matrix[i][j] < 0) {
                    negcount++;
                }
                minn = min(minn, abs(matrix[i][j]));
            }
        }

        if (negcount % 2 != 0) {
            summ -= 2 * minn;
        }

        return summ;
    }
};