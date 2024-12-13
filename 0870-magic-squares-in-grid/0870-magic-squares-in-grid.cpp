class Solution {
public:
    template<typename T, typename U>
    bool all_equal(T&& t, U&& u)
    {
        return (t == u);
    }
    
    template<typename T, typename U, typename... Ts>
    bool all_equal(T&& t, U&& u, Ts&&... args)
    {
        return (t == u) && all_equal(u, std::forward<Ts>(args)...);
    }

    bool areNumbersInRange(vector<vector<int>>& grid, int row, int col) {
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (grid[i][j] < 1 || grid[i][j] > 9) return false;
            }
        }
        return true;
    }

    bool areNumbersDistinct(vector<vector<int>>& grid, int row, int col) {
        vector<int> appeared(10, -1);  // Size 10 filled with -1 for not appeared
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                int num = grid[i][j];
                if (appeared[num] == 100) return false;
                appeared[num] = 100;
            }
        }
        return true;
    }

    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        // rowsum[0] += grid[row + 0][col + 0-2]
        // rowsum[1] += grid[row + 1][col + 0-2]
        // rowsum[2] += grid[row + 2][col + 0-2]
        vector<int> rowsum(3, 0);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                rowsum[i] += grid[row + i][col + j];
            }
        }

        // colsum[0] += grid[row + 0-2][col + 0]
        // colsum[1] += grid[row + 0-2][col + 1]
        // colsum[2] += grid[row + 0-2][col + 2]
        vector<int> colsum(3, 0);
        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < 3; i++) {
                colsum[j] += grid[row + i][col + j];
            }
        }

        // diasum[0] += grid[row + 0-2][col + 0-2]
        // diasum[1] += grid[row + 0-2][col + 2-0]
        vector<int> diasum(2, 0);
        for (int i = 0; i < 3; i++) {
            diasum[0] += grid[row + i][col + i];
        }
        for (int i = 0; i < 3; i++) {
            diasum[1] += grid[row + i][col + (2 - i)];
        }

        for (int i = 0; i < 3; i++) {
            cout << "rowsum " << i << " = " << rowsum[i] << endl;
        }
        for (int i = 0; i < 3; i++) {
            cout << "colsum " << i << " = " << colsum[i] << endl;
        }
        for (int i = 0; i < 2; i++) {
            cout << "diasum " << i << " = " << diasum[i] << endl;
        }

        //return (rowsum[0] == rowsum[1]) && (rowsum[1] == rowsum[2])
        //        && (rowsum[2] == colsum[0]) && (colsum[0] == colsum[1])
        //        && (colsum[1] == colsum[2]) && (colsum[2] == diasum[0])
        //        && (diasum[0] == diasum[1]);
                
        return all_equal(rowsum[0], rowsum[1], rowsum[2],
                        colsum[0], colsum[1], colsum[2],
                        diasum[0], diasum[1]);
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res = 0;
        int row = grid.size();
        int col = grid[0].size();

        for (int i = 0; i < row - 2; i++) {
            for (int j = 0; j < col - 2; j++) {
                if (areNumbersInRange(grid, i, j)
                    && areNumbersDistinct(grid, i, j)
                    && isMagicSquare(grid, i, j)) {
                        res++;
                    }
            }
        }
        return res;
    }
};