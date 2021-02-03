<?php
/**
 * https://leetcode.com/problems/3sum/
 */

class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function threeSum($nums) {
        if (count($nums) < 3) {
            return [];
        }
        
        $numCountMap = $this->createNumCountMap($nums);
        
        $rst = [];
        foreach ($numCountMap as $num => $count) {
            --$numCountMap[$num];
            if ($numCountMap[$num] === 0) {
                unset($numCountMap[$num]);
            }
            
            // using array_merge() here is too expensive
            $this->threeSumWithPivot($rst, $num, $numCountMap);
            
            // avoid duplicate
            unset($numCountMap[$num]);
        }
        return $rst;
    }
    
    /**
     * @param Integer[] $nums
     * @return array [num (int) => count (int)]
     */
    private function createNumCountMap($nums) {
        $rst = [];
        $totalCount = count($nums);
        for ($idx = 0; $idx < $totalCount; ++$idx) {
            if (!array_key_exists($nums[$idx], $rst)) {
                $rst[$nums[$idx]] = 1;
            } else {
                ++$rst[$nums[$idx]];
            }
        }
        return $rst;
    }
    
    /**
     * @param array $rst 3Sum result.
     * @param Integer $pivot The first number of resulted triplets. 
     * @param array $numCountMap [num (int) => count (int)]
     */
    private function threeSumWithPivot(&$rst, $pivot, $numCountMap) {
        $sum = -$pivot;
        $half = $sum / 2;
        foreach ($numCountMap as $num => $count) {
            if ($num > $half) {
                // avoid duplicate
                continue;
            }
            
            $expected = $sum - $num;
            if ($expected === $num && $numCountMap[$expected] >= 2
                || $expected !== $num && array_key_exists($expected, $numCountMap)
            ) {
                $rst[] = [$pivot, $num, $expected];
            }
        }
    }
}
