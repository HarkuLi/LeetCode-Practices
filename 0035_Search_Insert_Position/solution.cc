/**
 * Problem: https://leetcode.com/problems/search-insert-position/
 *
 * Idea: Binary search
 * 1.  Initialize "start" position as `0`, "end" position as the size of input
 *     array.
 * 2.  Until only 1 number remains among the interval [start, end), iteratively
 *     pick the "middle" position between "start" and "end".
 *     *   If the number at "middle" is larger than the target, then use the
 *         "middle" as the new "end".
 *     *   If the number at "middle" is less than the target, then use the
 *         "middle" as the new "start".
 *     *   If the number at "middle" is equal to the target, then return the
 *         index directly.
 * 3.  Once only 1 number remains among the interval [start, end),
 *     *   If the number at "start" is larger than or equal to the target, then
 *         return the index of "start".
 *     *   Otherwise, return the index next to "start".
 *
 * Time Complexity: O(log(n)), where n is the size of input array.
 *
 * Space Complexity: Θ(1)
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        size_t start = 0;
        size_t end = nums.size();

        while (end - start > 1) {
            size_t middle = (start + end) / 2;

            if (nums[middle] > target) {
                end = middle;
            } else if (nums[middle] < target) {
                start = middle;
            } else {
                return middle;
            }
        }

        return nums[start] >= target ? start : start + 1;
    }
};
