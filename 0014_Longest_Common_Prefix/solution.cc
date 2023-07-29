/**
 * Idea:
 * 1. Find the minimum string length.
 * 2. Compare each character of each string until the minimum index, and return
 *    the substring until the previous index if encountering the first different
 *    character.
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }

        // find the minimum string length
        size_t min_str_len = 1000;
        for (string& str : strs) {
            if (str.length() < min_str_len) {
                min_str_len = str.length();
            }
        }

        if (min_str_len == 0) {
            return "";
        }

        auto input_size = strs.size();
        for (size_t idx = 0; idx < min_str_len; ++idx) {
            char letter = strs[0][idx];

            for (string& str : strs) {
                if (str[idx] != letter) {
                    return strs[0].substr(0, idx);
                }
            }
        }

        return strs[0].substr(0, min_str_len);
    }
};
