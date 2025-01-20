class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();

        // move stones to the right
        for (auto& row : box) {
            int stonequeue = 0;
            for (int j = 0; j < n; j++) {
                // put stones in the "queue"
                if (row[j] == '#') {
                    row[j] = '.';
                    stonequeue++;
                }
                // when the obstacle is encountered, empty the queue
                // and put stones collected so far behind the wall
                if (row[j] == '*') {
                    while (stonequeue > 0) {
                        row[j - stonequeue] = '#';
                        stonequeue--;
                    }
                }
            }
            // end of the array reached, empty the queue
            while (stonequeue > 0) {
                row[n - stonequeue] = '#';
                stonequeue--;
            }
        }

        // rotate the matrix
        vector<vector<char>> rotated(n, vector<char>(m, '0'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rotated[i][j] = box[m - 1 - j][i];
            }
        }

        return rotated;
    }
};