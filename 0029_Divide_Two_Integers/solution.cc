/**
 * Idea:
 * 1.  Consider the edge case `−2^31 / -1` and return `2^31 - 1` directly.
 * 2.  Compute the quotient for dividing dividend's absolute value by divisor's
 *     absolute value (unsigned int division), and change the sign of result if
 *     the signs of dividend and divisor are opposite.
 *     *   e.g. 10 / -4 = -2, so we compute 10 / 4 = 2 and change the sign of
 *         result.
 *     *   The absolute value and sign changing is performed via
 *         `static_cast<>()` and negative is only applied on unsigned value to
 *          avoid any undefined behavior.
 * 3.  Unsigned int division is solved by divide-and-conquer.
 *     *   Let ⌊dividend / 2⌋ / divisor = q' ... r'.
 *     *   quotient = q' * 2.
 *     *   remainder = r' * 2, and plus 1 if the dividend is odd.
 *     *   If remainder >= divisor, then remainder = remainder - divisor,
 *         and quotient = quotient + 1.
 *
 * Time Complexity: O(log(n)), where n is the dividend.
 *
 * Space Complexity: O(log(n)), where n is the dividend. (because of recursion)
 *
 * References:
 * 1.  https://stackoverflow.com/questions/17313579/is-there-a-safe-way-to-get-the-unsigned-absolute-value-of-a-signed-integer-with
 */

#include <climits>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        unsigned int remainder = 0;
        unsigned int quotient = divide(uabs(dividend), uabs(divisor), remainder);

        return static_cast<int>(dividend > 0 ^ divisor > 0 ? -quotient : quotient);
    }

private:
    unsigned int uabs(int input) {
        return input >= 0
            ? static_cast<unsigned int>(input)
            : -static_cast<unsigned int>(input);
    }

    unsigned int divide(
        unsigned int dividend,
        unsigned int divisor,
        unsigned int& remainder
    ) {
        if (dividend == divisor) {
            remainder = 0;
            return 1;
        }

        if (dividend == 0) {
            remainder = 0;
            return 0;
        }

        if (divisor == 1) {
            remainder = 0;
            return dividend;
        }

        if (dividend < divisor) {
            remainder = dividend;
            return 0;
        }

        unsigned int half_dividend = dividend >> 1;
        unsigned int odd = dividend - half_dividend - half_dividend;

        if (half_dividend < divisor) {
            remainder = dividend - divisor;
            return 1;
        }

        int quotient = divide(half_dividend, divisor, remainder);
        quotient += quotient;
        remainder += (remainder + odd);
        if (remainder >= divisor) {
            remainder -= divisor;
            ++quotient;
        }

        return quotient;
    }
};
