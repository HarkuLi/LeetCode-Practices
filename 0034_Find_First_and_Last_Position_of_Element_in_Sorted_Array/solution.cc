/**
 * Problem: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 *
 * Idea:
 * 1.  Perform binary search until picking a target as middle, and thus we have
 *     a 3-tuple - {start, middle (target), end}. The subarray formed by the
 *     "start" and "end" will look like:
 *     [..., first target, ..., target (middle), ..., last target, ...]
 *     *   If there is no target found until the end, then return {-1, -1}.
 * 2.  Perform binary search on the [start, middle) subarray to find the first
 *     target. The [start, middle) subarray will look like:
 *     [..., first target, ..., target]
 *     *   If we pick up a middle that is a target but its previous value isn't
 *         a target, then the middle is the first target.
 * 3.  Perform binary search on the [middle, end) subarray to find the last
 *     target. The [middle, end) subarray will look like:
 *     [target, ..., (last) target, ...]
 *     *   If we pick up a middle that is a target but its next value isn't a
 *         target, then the middle is the last target.
 *
 * Time Complexity: O(log(n)), where n is the size of input.
 *
 * Space Complexity: Θ(1)
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty() || target < nums.front() || target > nums.back()) {
            return vector<int>(2, -1);
        }

        int start = 0;
        int end = nums.size();
        int middle = (start + end) / 2;
        for (;end - start > 1 && nums[middle] != target; middle = (start + end) / 2) {
            if (nums[middle] > target) {
                end = middle;
            } else {
                start = middle;
            }
        }

        if (end - start == 1) {
            return nums[start] == target
                ? vector<int>(2, start)
                : vector<int>(2, -1);
        }

        return vector<int>{
            findFirst(nums, start, middle, target),
            findLast(nums, middle, end, target),
        };
    }

private:
    /**
     * Handle the [..., (first) target, ..., target] part.
     */
    int findFirst(vector<int>& nums, int start, int end, int target) {
        if (nums[start] == target) {
            // Every elements in the part are the target.
            return start;
        }

        if (nums[end - 1] < target) {
            // There is no target in this part, and it means the first target
            // occurs at the "end" position.
            return end;
        }

        while (end - start > 1) {
            int middle = (start + end) / 2;

            if (nums[middle] < target) {
                start = middle;
            } else if (nums[middle - 1] == target) { // nums[middle] = target
                end = middle;
            } else {
                return middle;
            }
        }

        return start;
    }

    /**
     * Handle the [target, ..., (last) target, ...] part.
     */
    int findLast(vector<int>& nums, int start, int end, int target) {
        if (nums[end - 1] == target) {
            // Every elements in the part are the target.
            return end - 1;
        }

        // The index "start + 1" is safe, because the element at "end - 1" isn't the target.
        if (nums[start + 1] > target) {
            // There is only a target in this part, and it means the last target
            // occurs at the "start" position.
            return start;
        }

        while (end - start > 1) {
            int middle = (start + end) / 2;

            if (nums[middle] > target) {
                end = middle;
            } else if (nums[middle + 1] == target) { // nums[middle] = target
                start = middle;
            } else {
                return middle;
            }
        }

        return start;
    }
};
