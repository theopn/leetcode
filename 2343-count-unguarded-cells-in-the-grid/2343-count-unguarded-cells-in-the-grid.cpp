#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // 0 for unguarded
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // 1 for walls
        for (auto wall : walls) {
            grid[wall[0]][wall[1]] = 1;
        }

        // 1 for guards since they are practically the same as walls
        for (auto guard : guards) {
            grid[guard[0]][guard[1]] = 1;
        }

        int unguarded = m * n - walls.size() - guards.size();
        // 2 for unguarded
        for (auto guard : guards) {
            int row = guard[0], col = guard[1];

            // when traversing there are 3 cases:
            // 1. the coordinate we are trying to move is out of range or blocked by something -> stop the traversal
            // 2. the cell is already guarded by another guard -> proceed with traversal
            // 3. the cell is unguraded -> mark it guarded and proceed with traversal
//
            // traverse north
            for (int roww = row - 1; roww >= 0; roww--) {
                if (grid[roww][col] == 1) break;
                if (grid[roww][col] == 0) {
                    grid[roww][col] = 2;
                    unguarded--;
                }
            }

            // traverse south
            for (int roww = row + 1; roww < m; roww++) {
                if (grid[roww][col] == 1) break;
                if (grid[roww][col] == 0) {
                    grid[roww][col] = 2;
                    unguarded--;
                }
            }

            // traverse east
            for (int coll = col + 1; coll < n; coll++) {
                if (grid[row][coll] == 1) break;
                if (grid[row][coll] == 0) {
                    grid[row][coll] = 2;
                    unguarded--;
                }
            }

            // traverse west
            for (int coll = col - 1; coll >= 0; coll--) {
                if (grid[row][coll] == 1) break;
                if (grid[row][coll] == 0) {
                    grid[row][coll] = 2;
                    unguarded--;
                }
            }
         }
        
        return unguarded;
    }

    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        return 0;
    }
};