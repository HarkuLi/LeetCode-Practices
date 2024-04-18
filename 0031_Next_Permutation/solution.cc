/**
 * Idea:
 * 1.  Find the index for the start of descending subarray.
 *     *   e.g. [2, 4, 3, 1] => [2, "4", 3, 1]
 * 2.  If the start of descending subarray is index 0, it means the input is a
 *     descending array, and there is no larger permutation. Then, the next
 *     permutation is its reverse.
 * 3.  Otherwise, the previous number of the start of descending subarray should
 *     step up - it should swap for the later number that is least greater than
 *     it.
 *     *   e.g. ["2", 4, 3, 1] => ["3", 4, 2, 1]
 * 4.  After the swap, the descending subarray must keep descending. We can
 *     resolve the next permutation by then reversing the descending subarray.
 *     *   e.g. [3, "4, 2, 1"] => [3, "1, 2, 4"]
 *
 * Time Complexity: O(n), where n is the size of input.
 *
 * Space Complexity: Θ(1)
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        size_t descending_begin = findDescendingBegin(nums);

        if (descending_begin == 0) {
            // no larger permutation
            reverse(nums.begin(), nums.end());
            return;
        }

        size_t idx_to_step = descending_begin - 1;
        // Find the later number that is least greater than the previous number
        // of the descending begin, and swap them (step).
        for (size_t i = nums.size() - 1; i >= descending_begin; --i) {
            if (nums[i] > nums[idx_to_step]) {
                swap(nums[i], nums[idx_to_step]);
                break;
            }
        }

        reverse(nums.begin() + descending_begin, nums.end());
    }

private:
    size_t findDescendingBegin(vector<int>& nums) {
        for (size_t i = nums.size() - 1; i > 0; --i) {
            if (nums[i] > nums[i - 1]) {
                return i;
            }
        }

        return 0;
    }
};
