/**
 * Idea: KMP algorithm
 * 1.  Compute an array of LPS (longest proper prefix which is also a proper
 *     suffix) lengths for each prefix of the needle.
 * 2.  Iterate each character of the haystack with the help of LPS array to find
 *     the needle.
 *
 * Time Complexity:
 * O(m + n) or O(m) (because m >= n), where m is the length of haystack, and n
 * is the length of needle. Note that although we have a while loop for walking
 * through indices of `needle_lps_sizes` in the for loop for haystack
 * characters, and the worst case seems to be O(m * n). However, `needle_idx`
 * only may increases by one whenever `haystack_idx` increases by 1, so the
 * actual worst case should be O(2m), and thus O(m).
 *
 * Space Complexity: Θ(n), where n is the length of needle.
 *
 * References:
 * 1.  https://www.youtube.com/watch?v=0iDiUuHZE_g
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t haystack_size = haystack.size();
        size_t needle_size = needle.size();

        // Compute LPS array.
        vector<size_t> needle_lps_sizes(needle_size, 0);
        for (size_t prefix_size = 0, i = 1; i < needle_size; ++i) {
            while (prefix_size > 0 && needle[prefix_size] != needle[i]) {
                prefix_size = needle_lps_sizes[prefix_size - 1];
            }

            if (needle[prefix_size] == needle[i]) {
                ++prefix_size;
                needle_lps_sizes[i] = prefix_size;
            }
        }

        // Main algorithm.
        for (size_t needle_idx = 0, haystack_idx = 0; haystack_idx < haystack_size; ++haystack_idx) {
            while (needle_idx > 0 && haystack[haystack_idx] != needle[needle_idx]) {
                needle_idx = needle_lps_sizes[needle_idx - 1];
            }

            if (haystack[haystack_idx] == needle[needle_idx]) {
                ++needle_idx;
            }

            if (needle_idx == needle_size) {
                return haystack_idx - needle_size + 1;
            }
        }

        return -1;
    }
};
