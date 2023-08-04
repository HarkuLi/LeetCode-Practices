/**
 * Input:
 * -2147483648 <= x <= 2147483647
 *
 * Idea:
 * 1. Reverse the input until 9th digit from the least significant digit.
 * 2. According to the reversed value at that point, we can determine whether
 *    the result will go outside the range.
 * 3. Continue and finish the reversion if it won't go outside the range, or
 *    return 0.
 */

class Solution {
public:
    int reverse(int x) {
        int result = 0;

        for (int digit_cnt = 0; x != 0; ++digit_cnt) {
            // We don't need to care about (digit_cnt == 9 && abs(result) == 214748364 && abs(x % 10) > 7)
            // because corresponding inputs are out of range of signed 32-bit integer and thus impossible.
            if (digit_cnt == 9 && abs(result) > 214748364) {
                return 0;
            }

            result = result * 10 + x % 10;
            x /= 10;
        }

        return result;
    }
};
