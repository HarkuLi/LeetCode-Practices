/**
 * Idea:
 * 1. Parse input digit by digit.
 * 2. Compare digits from head and tail one by one.
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else if (x < 10) {
            return true;
        }

        // Parse input.
        int digits[10];
        int length = 0;
        for (length = 0; x > 0; ++length) {
            digits[length] = x % 10;
            x /= 10;
        }

        // Check palindrome.
        int middle_idx = length / 2;
        for (int i = 0; i < middle_idx; ++i) {
            if (digits[i] != digits[length - i - 1]) {
                return false;
            }
        }
        return true;
    }
};
