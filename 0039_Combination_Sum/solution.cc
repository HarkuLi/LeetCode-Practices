/**
 * Problem: https://leetcode.com/problems/combination-sum/
 *
 * Idea:
 * 1.  For each number that is less than or equal to the target, pick it into
 *     the "prefix", and solve the sub-problem for `[current number, end) of
 *     candidates` and `target = target - current number` recursively.
 *     *   e.g. For {candidates = [2,3,6,7], target = 7}, solve
 *         {candidates = [2,3,6,7], prefix = [2], target = 5 (7 - 2)},
 *         {candidates = [3,6,7], prefix = [3], target = 4 (7 - 3)}, ...
 *     *   If the target goes to zero, then add the current prefix into the
 *         result.
 *
 * Best Runtime: 0 ms
 *
 * Best Memory: 12.24 MB
 *
 * Time Complexity: O(t/m * 2^{n * t/m}), where n is the number of candidates;
 * t is the target; m is the minimum candidate.
 * The first `t/m` represent the worst case for length of a solution
 * (e.g. 3 = 1 + 1 + 1), and it is the cost for the copy after finding out a
 * solution. Next, when we consider the case for not picking repeated
 * candidates (Combination Sum II), the maximum number of possible solutions is
 * 2^n (each candidate is picked or not picked). And this question can be
 * converted into "Combination Sum II" by replicate each candidate up to floor
 * of `target/candidate`, so the worst case for the number of candidates after
 * the replication will be `n * t/m`, where `t/m` is the worst case for the
 * number of a candidate will be after the replication. In conclusion, the worst
 * case for the numbser of possible solutions would be `2^{n * t/m}`, and each
 * solution requires at most `t/m` to be copied into the result vector.
 * Therefore, The time complexity is O(t/m * 2^{n * t/m}).
 *
 * Space Complexity: O(t/m), where t is the target; m is the minimum candidate.
 * By default, the output space is ignored. And we only need a vector for
 * prefixes where the maximum length would be `t/m`.
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> prefix;

        solvePartial(candidates, target, 0, result, prefix);

        return result;
    }

private:
    void solvePartial(
        vector<int>& candidates,
        int target,
        size_t candidate_start,
        vector<vector<int>>& result,
        vector<int>& prefix
    ) {
        if (target == 0) {
            result.push_back(prefix);
            return;
        }

        // If the `candidates` has been sorted in advance, we can make
        // `candidates[i] <= target` as one stop condition of the for loop to
        // achieve early stops. Through experiments, however, it makes the
        // average runtime worse.
        for (size_t i = candidate_start; i < candidates.size(); ++i) {
            if (candidates[i] <= target) {
                prefix.push_back(candidates[i]);
                solvePartial(
                    candidates,
                    target - candidates[i],
                    i,
                    result,
                    prefix
                );
                prefix.pop_back();
            }
        }
    }
};
