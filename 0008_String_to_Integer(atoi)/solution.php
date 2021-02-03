<?php
/**
 * https://leetcode.com/problems/string-to-integer-atoi/
 */

class Solution {
    private const UPPER_BOUND = 2147483647;
    private const LOWER_BOUND = -2147483648;

    /**
     * @param String $s
     * @return Integer
     */
    function myAtoi($s) {
        $s = ltrim($s);
        
        if ($s === "") {
            return 0;
        }
        
        if ($s[0] !== '-' && $s[0] !== '+' && !is_numeric($s[0])) {
            return 0;
        }
        
        $strLen = strlen($s);
        $isNegative = $this->isNegative($s);
        $firstNonZeroIdx = is_numeric($s[0]) ? 0 : 1;
        for (; $firstNonZeroIdx < $strLen; ++$firstNonZeroIdx) {
            if ($s[$firstNonZeroIdx] !== '0') {
                break;
            }
        }
        if ($firstNonZeroIdx === $strLen) {
            return 0;
        }
        
        // discard non-digit characters
        for ($i = $firstNonZeroIdx; $i < $strLen; ++$i) {
            if (!is_numeric($s[$i])) {
                break;
            }
        }
        $s = substr($s, $firstNonZeroIdx, $i - $firstNonZeroIdx);
        if ($isNegative) {
            $s = '-' . $s;
        }
        
        if ($this->isOutOfUpperBound($s)) {
            return self::UPPER_BOUND;
        }
        
        if ($this->isOutOfLowerBound($s)) {
            return self::LOWER_BOUND;
        }
        
        return $this->strToInt($s);
    }
    
    private function isOutOfUpperBound($str) {
        return $this->compareStrNum($str, self::UPPER_BOUND . '') === 1;
    }
    
    private function isOutOfLowerBound($str) {
        return $this->compareStrNum($str, self::LOWER_BOUND . '') === -1;
    }
    
    /**
     * @param String $str1
     * @param String $str2
     * @return Integer $str1 > $str2 => 1, $str1 < $str2 => -1, $str1 = $str2 => 0
     */
    private function compareStrNum($str1, $str2) {
        if ($str1 === $str2) {
            return 0;
        }
        
        if ($this->isNegative($str1) && !$this->isNegative($str2)) {
            return -1;
        }
        
        if (!$this->isNegative($str1) && $this->isNegative($str2)) {
            return 1;
        }
        
        // signs are the same
        return !$this->isNegative($str1)
            ? $this->comparePositiveStrNum($str1, $str2)
            : $this->compareNegativeStrNum($str1, $str2);
    }
    
    private function isNegative($str) {
        return $str[0] === '-';
    }
    
    private function comparePositiveStrNum($str1, $str2) {
        $len1 = strlen($str1);
        $len2 = strlen($str2);
        
        if ($len1 > $len2) {
            return 1;
        }
        
        if ($len1 < $len2) {
            return -1;
        }
        
        for ($i = 0; $i < $len1; ++$i) {
            if ($str1[$i] === $str2[$i]) {
                continue;
            }
            
            return $str1[$i] > $str2[$i] ? 1 : -1;
        }
        
        return 0;
    }
    
    private function compareNegativeStrNum($str1, $str2) {
        $len1 = strlen($str1);
        $len2 = strlen($str2);
        
        if ($len1 > $len2) {
            return -1;
        }
        
        if ($len1 < $len2) {
            return 1;
        }
        
        // $str1[0], $str2[0] are negative signs.
        for ($i = 1; $i < $len1; ++$i) {
            if ($str1[$i] === $str2[$i]) {
                continue;
            }
            
            return $str1[$i] > $str2[$i] ? -1 : 1;
        }
        
        return 0;
    }
    
    private function strToInt($str) {
        $isNegative = $str[0] === '-';
        
        $strLen = strlen($str);
        $startIdx = is_numeric($str[0]) ? 0 : 1;
        $multiple = pow(10, $strLen - $startIdx - 1);
        
        $rst = 0;
        for ($i = $startIdx; $i < $strLen; ++$i) {
            $rst += $str[$i] * $multiple;
            $multiple /= 10;
        }
        
        return !$isNegative ? $rst : -$rst;
    }
}
