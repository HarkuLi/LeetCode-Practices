<?php
/**
 * https://leetcode.com/problems/3sum-closest/
 */

class Solution {
    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer
     */
    function threeSumClosest($nums, $target) {
        sort($nums);
        $numLength = count($nums);
        $minDiff = PHP_INT_MAX;
        // format: [num => null]
        $computedNumSet = [];
        for ($i = 0; $i < $numLength; ++$i) {
            $pivot = $nums[$i];
            if (array_key_exists($pivot, $computedNumSet)) {
                continue;
            }
            
            $computedNumSet[$pivot] = null;
            $idxL = $i + 1;
            $idxR = $numLength - 1;
            while ($idxL < $idxR) {
                $sum = $pivot + $nums[$idxL] + $nums[$idxR];
                $diff = $target - $sum;
                if ($diff === 0) {
                    return $sum;
                }
                
                if (abs($diff) < abs($minDiff)) {
                    $minDiff = $diff;
                }
                
                if ($sum > $target) {
                    --$idxR;
                } else {
                    ++$idxL;
                }
            }
        }
        return $target - $minDiff;
    }
}
