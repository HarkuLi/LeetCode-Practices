/**
 * Idea: Build solution by Depth-First Search (DFS).
 * 1.  Track current prefix, remaining start parentheses (`(`) and unpaired 
 *     start parentheses.
 * 2.  If there is remaining start parenthesis, then recursively find all
 *     possible solutions about current prefix appended with a start
 *     parenthesis.
 * 3.  If there is unpaired start parenthesis, then recursively find all
 *     possible solutions about current prefix appended with an end parenthesis
 *     (`)`).
 * 4.  If there is no remaining start parenthesis and unpaired start
 *     parentheses, it means a solution is formed. Thus, record the current
 *     prefix.
 * 5.  Return the result.
 *
 * Time Complexity: Θ(N), where N is the number of solutions.
 * Space Complexity:
 * Θ(N * n), where N is the number of solutions, n is the number of pairs of
 * parentheses.
 *
 * Refer to below links to see how to compute the number of solutions:
 * 1.  https://math.stackexchange.com/questions/2991347
 * 2.  https://en.wikipedia.org/wiki/Catalan_number
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> rst;
        string prefix(n * 2, '\0');
        resolvePart(rst, prefix, 0, n, 0);
        return rst;
    }

private:
    void resolvePart(
        vector<string> &rst,
        string &prefix,
        size_t prefix_len,
        int remaining_starts,
        int unpaired_starts
    ) {
        if (remaining_starts == 0 && unpaired_starts == 0) {
            rst.push_back(prefix);
            return;
        }

        if (remaining_starts > 0) {
            prefix[prefix_len] = '(';
            resolvePart(rst, prefix, prefix_len + 1, remaining_starts - 1, unpaired_starts + 1);
        }

        if (unpaired_starts > 0) {
            prefix[prefix_len] = ')';
            resolvePart(rst, prefix, prefix_len + 1, remaining_starts, unpaired_starts - 1);
        }
    }
};
