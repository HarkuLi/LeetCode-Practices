/**
 * Idea:
 * 1. Store symbol to value map as a private static property.
 * 2. Add a redundant space char to the end of string to prevent accessing index
 *    out of range.
 * 3. Look ahead one symbol during iteration to determine addition or
 *    subtraction.
 */

class Solution {
public:
    int romanToInt(string s) {
        s.push_back(' ');

        int result = 0;
        for (int i = 0; i < s.length() - 1; ++i) {
            char symbol = s[i];
            char next_symbol = s[i + 1];

            if (
                (symbol == 'I' && (next_symbol == 'V' || next_symbol == 'X')) ||
                (symbol == 'X' && (next_symbol == 'L' || next_symbol == 'C')) ||
                (symbol == 'C' && (next_symbol == 'D' || next_symbol == 'M'))
            ) {
                result += values[next_symbol] - values[symbol];
                ++i;
            } else {
                result += values[symbol];
            }
        }

        return result;
    }

private:
    inline static unordered_map<char, int> values = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
};
