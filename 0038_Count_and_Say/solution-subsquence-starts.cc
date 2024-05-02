/**
 * Problem: https://leetcode.com/problems/count-and-say/
 *
 * Idea: Bottom-up dynamic programming; record sub-sequence starts
 * 1.  Use bottom-up approach to build sequences from [1]st to [n]th.
 * 2.  For [k]th sequence, build it from [k-1]th sequence and sub-sequence
 *     starts.
 *     *   Record start indices of every sub-sequence (consecutive identical
 *         digits), so that we don't need to iterate each character for sequence
 *         of each level.
 * 3.  Finally, we will get the [n]th sequence, which is the result to return.
 *
 * Best Runtime: 0 ms
 *
 * Best Memory: 9.44 MB
 *
 * Time Complexity: O(2^n), where n is the input.
 * For the best case, each sequence is composed of 3-digits sub-sequences, so we
 * can iterate just 1/3 length of a sequence. However, it still doesn't affect
 * the time complexity for just multiplying it by 1/3 (constant).
 *
 * Space Complexity: O(2^n), where n is the input.
 * Although we use additional two vectors for storing sub-sequence starts for
 * current sequence and previous sequence, it doesn't affect the space
 * complexity because it is just multiplied by 2 (constant).
 */

class Solution {
public:
    string countAndSay(int n) {
        string curr = "1";
        auto seq_starts = make_unique<vector<size_t>>(1, 0);
        seq_starts->push_back(curr.size());

        for (size_t i = 2; i <= n; ++i) {
            string prev = curr;
            auto prev_seq_starts = move(seq_starts);
            curr = "";
            seq_starts = make_unique<vector<size_t>>();

            // iterate sequence starts of previous string
            char last_digit = '\0';
            for (auto it = prev_seq_starts->begin(); it + 1 != prev_seq_starts->end(); ++it) {
                auto next = it + 1;
                char count = '0' + (*next - *it); // the count is alway less than 4
                char digit = prev[*it];

                if (count != last_digit) {
                    seq_starts->push_back(curr.size());
                    last_digit = count;
                }
                curr += count;

                if (digit != last_digit) {
                    seq_starts->push_back(curr.size());
                    last_digit = digit;
                }
                curr += digit;
            }
            seq_starts->push_back(curr.size());
        }

        return curr;
    }
};
