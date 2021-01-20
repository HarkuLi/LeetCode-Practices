<?php
/**
 * https://leetcode.com/problems/longest-palindromic-substring/
 */

/**
 * Manacher's Algorithm
 * @see http://web.ntnu.edu.tw/~algo/Palindrome.html#3
 */
class Solution {
    /**
     * @param String $s
     * @return String
     */
    function longestPalindrome($s) {
        $dotSplitStr = '.' . implode('.', str_split($s)) . '.';
        $halfLenMap = [0 => 1];
        
        // record center and rightBorder of currently most right palindromic substring
        $center = $rightBorder = 0;
        
        $length = strlen($dotSplitStr);
        for ($i = 1; $i < $length; ++$i) {
            if ($i > $rightBorder) {
                $halfLenMap[$i] = $this->extend($dotSplitStr, $i, $i);
                $center = $i;
                $rightBorder = $i + $halfLenMap[$i] -1;
                continue;
            }
            
            // mapping point based on $center
            $mappingIndex = $center - ($i - $center);
            $lengthToBorder = $rightBorder - $i + 1;
            
            if ($halfLenMap[$mappingIndex] === $lengthToBorder) {
                $halfLenMap[$i] = $lengthToBorder
                    + $this->extend($dotSplitStr, $i - $lengthToBorder, $i + $lengthToBorder);
                $center = $i;
                $rightBorder = $i + $halfLenMap[$i] -1;
            } else {
                $halfLenMap[$i] = min($halfLenMap[$mappingIndex], $lengthToBorder);
            }
        }
        
        $maxLength = $maxLengthIndex = 0;
        for ($i = 0; $i < $length; ++$i) {
            if ($halfLenMap[$i] > $maxLength) {
                $maxLength = $halfLenMap[$i];
                $maxLengthIndex = $i;
            }
        }
        
        return str_replace(
            '.',
            '',
            substr($dotSplitStr, $maxLengthIndex - $maxLength + 1, $maxLength * 2 - 1)
        );
    }
    
    /**
     * @param String $str String to operate.
     * @param Integer $leftIdx Left index to start extend.
     * @param Integer $rightIdx Right index to start extend.
     * @return Integer Totally extended length.
     */
    private function extend($str, $leftIdx, $rightIdx) {
        $rst = 0;
        $strLen = strlen($str);
        while ($leftIdx >= 0 && $rightIdx < $strLen && $str[$leftIdx] === $str[$rightIdx]) {
            ++$rst;
            --$leftIdx;
            ++$rightIdx;
        }
        return $rst;
    }
}
