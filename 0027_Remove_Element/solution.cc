/**
 * Idea:
 * 1.  Use a variable to record result size, which is also the index to put a
 *     new result number.
 * 2.  Walk through the input array. For each number that isn't equal to `val`,
 *     copy it to the index `rst_size` and increase `rst_size`.
 *
 * Time Complexity: Θ(n), where n is the input array size.
 * Space Complexity: Θ(1)
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        size_t rst_size = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[rst_size++] = nums[i];
            }
        }

        return rst_size;
    }
};
