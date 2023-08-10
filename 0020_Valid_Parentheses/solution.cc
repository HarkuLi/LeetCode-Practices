/**
 * Idea:
 * 1. Use a string to store seen open parentheses.
 * 2. Iterate all characters in the input string.
 * 3. If encountering a close parenthesis, determine whether it matches the last
 *    seen open parenthesis. If it matches, pop the last seen open parenthesis;
 *    otherwise, return false.
 * 4. Finally, return true if there is no unmatched open parenthesis.
 *
 * Time Complexity: Θ(n), where n is the length of input string.
 * Space Complexity: O(n), where n is the length of input string.
 */

class Solution {
public:
    bool isValid(string s) {
        string parentheses = "";

        for (const char& c : s) {
            switch (c) {
                case '(':
                case '[':
                case '{':
                    parentheses.push_back(c);
                    break;
                case ')':
                    if (parentheses == "" || parentheses.back() != '(') {
                        return false;
                    }

                    parentheses.pop_back();
                    break;
                case ']':
                    if (parentheses == "" || parentheses.back() != '[') {
                        return false;
                    }

                    parentheses.pop_back();
                    break;
                case '}':
                    if (parentheses == "" || parentheses.back() != '{') {
                        return false;
                    }

                    parentheses.pop_back();
                    break;
                default:
                    break;
            }
        }

        return parentheses.empty();
    }
};
