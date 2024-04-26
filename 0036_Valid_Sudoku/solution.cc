/**
 * Problem: https://leetcode.com/problems/valid-sudoku/
 *
 * Idea:
 * 1.  Use a flag for each digit (1 - 9) to record digit usages for each row,
 *     column and sub-box.
 * 2.  Index each sub-box as: +-----------+
 *                            | 0 | 1 | 2 |
 *                            +-----------+
 *                            | 3 | 4 | 5 |
 *                            +-----------+
 *                            | 6 | 7 | 8 |
 *                            +-----------+
 * 3.  For each number in the board, check whether its row, column, and sub-box
 *     will occur repetition.
 *     *   If there is repetition, then return false for the invalid board.
 *     *   Otherwise, mark the number in its corresponding row, column, and
 *         sub-box as used.
 * 4.  If all number in the board passed validation, then the board is valid.
 *
 * Time Complexity: O(n^2), where n is the length of a board side.
 *
 * Space Complexity: Θ(n), where n is the length of a board side.
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row_digit_usage[kRowCount][9] = { false };
        bool col_digit_usage[kColCount][9] = { false };
        bool box_digit_usage[kSubBoxCount][9] = { false };

        for (size_t i = 0; i < kRowCount; ++i) {
            for (size_t j = 0; j < kColCount; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }

                int digit_idx = board[i][j] - '1';
                size_t box_no = (i / kSubBoxSide) * 3 + (j / kSubBoxSide);

                if (
                    row_digit_usage[i][digit_idx] ||
                    col_digit_usage[j][digit_idx] ||
                    box_digit_usage[box_no][digit_idx]
                ) {
                    return false;
                } else {
                    row_digit_usage[i][digit_idx] = true;
                    col_digit_usage[j][digit_idx] = true;
                    box_digit_usage[box_no][digit_idx] = true;
                }
            }
        }

        return true;
    }

private:
    static const size_t kRowCount = 9;
    static const size_t kColCount = 9;
    static const size_t kSubBoxCount = 9;
    static const size_t kSubBoxSide = 3;
};
