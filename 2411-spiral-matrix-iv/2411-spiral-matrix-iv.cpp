/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // direction vectors
        vector<pair<int, int>> directions { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int i = 0, j = 0, dir = 0;
        for (; head; head = head->next) {
            matrix[i][j] = head->val;

            // check if the new direction is invalid by checking the following:
            // 1. not within the left or upper bound (negative value)
            // 2. not within the right or lower bound (exceeded m or n)
            // 3. the value at the cell is already occupied (not -1)
            int ii = i + directions[dir].first, jj = j + directions[dir].second;
            if (ii < 0 || jj < 0
                || ii >= m || jj >= n
                || matrix[ii][jj] != -1) {
                dir = (dir + 1) % 4;  // if invalid, change direction
            }
            // actually assign the new direction
            i += directions[dir].first;
            j += directions[dir].second;
        }

        return matrix;
    }
};