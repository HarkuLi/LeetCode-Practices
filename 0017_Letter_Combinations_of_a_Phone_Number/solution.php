<?php
/**
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 */

class Solution {
    private const DIGIT_LETTERS_MAP = [
        2 => ['a', 'b', 'c'],
        3 => ['d', 'e', 'f'],
        4 => ['g', 'h', 'i'],
        5 => ['j', 'k', 'l'],
        6 => ['m', 'n', 'o'],
        7 => ['p', 'q', 'r', 's'],
        8 => ['t', 'u', 'v'],
        9 => ['w', 'x', 'y', 'z'],
    ];
    
    /**
     * @param String $digits
     * @return String[]
     */
    function letterCombinations($digits) {
        if ($digits === "") {
            return [];
        }

        $rst = [];
        $this->combinationsWithPrefix($rst, $digits, 0, "");
        return $rst;
    }
    
    private function combinationsWithPrefix(&$rst, $digits, $index, $prefix) {
        if ($index === strlen($digits)) {
            $rst[] = $prefix;
            return;
        }
        
        $letters = self::DIGIT_LETTERS_MAP[$digits[$index]];
        ++$index;
        foreach ($letters as $letter) {
            $this->combinationsWithPrefix($rst, $digits, $index, $prefix . $letter);
        }
    }
}
