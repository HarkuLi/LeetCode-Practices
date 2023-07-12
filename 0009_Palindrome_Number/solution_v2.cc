/**
 * Idea:
 * 1. Reverse half of the input, and store it as another integer.
 * 2. Compare left half part and reversed right half part of the input.
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else if (x < 10) {
            return true;
        } else if (x % 10 == 0) {
            return false;
        }

        int half_reverse = 0;
        while (x > half_reverse) {
            half_reverse = half_reverse * 10 + x % 10;
            x /= 10;
        }

        return x == half_reverse // when digit count is even
            || x == half_reverse / 10; // when digit count is odd
    }
};
