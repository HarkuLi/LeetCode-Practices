<?php
/**
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

class Solution {
    /**
    * @param String $s
    * @return Integer
    */
    function lengthOfLongestSubstring($s) {
        $totalLength = strlen($s);
        if ($totalLength <= 1) {
            return $totalLength;
        }
        
        $leftBound = 0;
        $charPositions = [];
        $max = 0;
        
        for ($rightBound = 0; $rightBound < $totalLength; ++$rightBound) {
            $char = $s[$rightBound];
            
            if (!array_key_exists($char, $charPositions) || $charPositions[$char] < $leftBound) {
                $charPositions[$char] = $rightBound;
                $max = max($max, $rightBound - $leftBound + 1);
                continue;
            }
            
            $leftBound = $charPositions[$char] + 1;
            $charPositions[$char] = $rightBound;
        }
        
        return $max;
    }
}
