/**
 * Idea:
 * 1.  Iterate over each character of the haystack.
 * 2.  If the number of remaining characters is less than the needle length, it
 *     means not found.
 * 3.  For each character of the haystack, examine whether the sub-string begins
 *     at the character is equal to the needle.
 *
 * Time Complexity:
 * O(m * n), where m is the length of haystack, and n is the length of needle.
 * Space Complexity: Θ(1)
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t haystack_size = haystack.size();
        size_t needle_size = needle.size();

        for (size_t i = 0; i < haystack_size; ++i) {
            if (haystack_size - i < needle_size) {
                return -1;
            }

            for (size_t j = 0; j < needle_size; ++j) {
                if (haystack[i + j] != needle[j]) {
                    break;
                } else if (j == needle_size - 1) {
                    return i;
                }
            }
        }

        return -1;
    }
};
