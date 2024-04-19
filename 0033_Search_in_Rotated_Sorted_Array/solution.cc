/**
 * Problem: https://leetcode.com/problems/search-in-rotated-sorted-array/
 *
 * Idea:
 * 1.  Pick the middle of the input array.
 * 2.  Examine whether the target might be in the right or left interval.
 *     *   If the interval includes pivot and "the target >= the interval start
 *         OR the target <= the interval end", then the target might be in the
 *         interval.
 *         *   Example for an interval including pivot: [7, 8, 0, 1, 2]
 *     *   If the interval doesn't include pivot and "the target >= the interval
 *         start AND the target <= the interval end", then the target might be
 *         in the interval.
 *         *   Example for an interval not including pivot: [0, 1, 2, 3, 4]
 * 3.  For the side that includes the target, pick the middle and repeat from
 *     step 2.
 * 4.  Until the size of examined interval decreses to 1, examine whether the
 *     remaining number is equal to the target.
 *
 * Time Complexity: O(log(n)), where n is the size of input.
 *
 * Space Complexity: Θ(1)
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        size_t start = 0;
        size_t end = nums.size();

        while (end - start > 1) {
            size_t middle = (start + end) / 2;

            if (isWithinInterval(nums, start, middle, target)) {
                end = middle;
            } else if (isWithinInterval(nums, middle, end, target)) {
                start = middle;
            } else {
                return -1;
            }
        }

        return nums[start] == target ? start : -1;
    }

private:
    bool isWithinInterval(vector<int>& nums, size_t start, size_t end, int target) {
        if (includePivot(nums, start, end)) {
            return target >= nums[start] || target <= nums[end - 1];
        }

        return target >= nums[start] && target <= nums[end - 1];
    }

    bool includePivot(vector<int>& nums, size_t start, size_t end) {
        return nums[end - 1] < nums[start];
    }
};
