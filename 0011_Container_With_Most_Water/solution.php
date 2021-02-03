<?php
/**
 * https://leetcode.com/problems/container-with-most-water/
 */

class Solution {
    /**
     * @param Integer[] $height
     * @return Integer
     */
    function maxArea($height) {
        $left = 0;
        $right = count($height) - 1;
        $width = $right - $left;
        $max = 0;
        
        while ($width >= 1) {
            $area = min($height[$right], $height[$left]) * $width;
            $max = max($max, $area);
            
            if ($height[$right] >= $height[$left]) {
                ++$left;
            } else {
                --$right;
            }
            --$width;
        }
        
        return $max;
    }
}
