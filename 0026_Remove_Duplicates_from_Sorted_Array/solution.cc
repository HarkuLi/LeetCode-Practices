/**
 * Idea:
 * 1.  Use a variable to record result size. Initial size is 1 because the
 *     problem promises that the minimum size of `nums` is 1. Therefore, we can
 *     regard the first elemnt of input array as the first element of result
 *     array, and iterate the input array from the second element.
 * 2.  Each number that isn't the same as its previous number implies a new
 *     distinct number. Thus, we should copy the number to the end position of
 *     the result array (at index `rst_size`) and increase the result size.
 * 3.  Once iterate throughout the input array, simply return the result size
 *     and we are done.
 *
 * Time Complexity: Θ(n), where n is the input array size.
 * Space Complexity: Θ(1)
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        size_t rst_size = 1;

        for (size_t probe = 1; probe < nums.size(); ++probe) {
            if (nums[probe] != nums[probe - 1]) {
                nums[rst_size++] = nums[probe];
            }
        }

        return rst_size;
    }
};
