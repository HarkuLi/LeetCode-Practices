/**
 * Problem: https://leetcode.com/problems/count-and-say/
 *
 * Idea: Bottom-up dynamic programming
 * 1.  Use bottom-up approach to build sequences from [1]st to [n]th.
 * 2.  For [k]th sequence, build it from [k-1]th sequence.
 *     *   Iterate each digit in the [k-1]th sequence, and convert each
 *         consecutive identical digits into Run-length encoding to form the
 *         [k]th sequence.
 *     *   We can observe that at least until [30]th sequence, the digits in the
 *         sequence won't grow up to be greater than 3 (and it seems to be true
 *         for any n). So that we can safely convert the length of each
 *         consecutive identical digits into a char.
 * 3.  Finally, we will get the [n]th sequence, which is the result to return.
 *
 * Best Runtime: 0 ms
 *
 * Best Memory: 7.51 MB
 *
 * Time Complexity: O(2^n), where n is the input.
 * In the worst case, though the sequence length won't grow up such fast in
 * fact, the length of [k]th sequence is the double of the length of [k-1]th
 * sequence. Therefore, the length of [k]th sequence is 1 * 2^{k-1}. The
 * algorithm iterates sequences of every levels, so the time complexity is
 * 1 + 1 * 2^1 + 1 * 2^2 + ... + 1 * 2^{n-1} = 1 * (2^n - 1) / 2 - 1 (sum of
 * geometric sequence) and thus is O(2^n).
 *
 * Space Complexity: O(2^n), where n is the input.
 * For each iteration, the algorithm stores [k]th sequence and [k-1]th sequence
 * at most. So the worst case is 2^{n-1} + 2^{n-2} = O(2^n).
 */

class Solution {
public:
    string countAndSay(int n) {
        string current = "1";

        for (size_t i = 2; i <= n; ++i) {
            // Adding the dummy char in an individual line instead of next line
            // indeed decreases memory usage, because it avoid creating a
            // temporary new string.
            current += '0';
            string prev = current;
            current = "";

            for (size_t start = 0, end = 1; end < prev.size(); ++end) {
                if (prev[end] != prev[start]) {
                    // The count is alway less than 4, so we can safely convert
                    // the count into a char in this way.
                    current += ('0' + (end - start));
                    current += prev[start];
                    start = end;
                }
            }
        }

        return current;
    }
};
