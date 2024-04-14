/**
 * Idea:
 * 1.  Call `string.find()`.
 *
 * Time Complexity:
 * O(m * n), where m is the length of haystack, and n is the length of needle.
 * Space Complexity: ?
 *
 * References:
 * 1.  https://cplusplus.com/reference/string/string/find
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};
