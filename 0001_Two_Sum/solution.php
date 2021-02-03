<?php
/**
 * https://leetcode.com/problems/two-sum/
 */

class Solution {
    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $indexMap = $this->getIndexMap($nums);
        
        $numCount = count($nums);
        for ($idx = 0; $idx < $numCount; ++$idx) {
            $num = $nums[$idx];
            $expectNum = $target - $num;
            
            if ($expectNum === $num) {
                if (count($indexMap[$num]) >= 2) {
                    // We can return directly because there is exactly one solution.
                    return $indexMap[$num];
                }
                
                continue;
            }
            
            if (array_key_exists($expectNum, $indexMap)) {
                return [$idx, $indexMap[$expectNum][0]];
            }
        }
        
        return [];
    }

    /**
     * format: [number -> [position1, position2, ...]]
     *
     * @return array
     */
    private function getIndexMap($nums) {
        $indexMap = [];
        $numCount = count($nums);
        for ($idx = 0; $idx < $numCount; ++$idx) {
            $num = $nums[$idx];
            if (array_key_exists($num, $indexMap)) {
                $indexMap[$num][] = $idx;
            } else {
                $indexMap[$num] = [$idx];
            }
        }
        return $indexMap;
    }
}
