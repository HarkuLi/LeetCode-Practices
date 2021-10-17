<?php
/**
 * https://leetcode.com/problems/two-sum/
 */

class Solution {
    /**
     * @param int[] $nums
     * @param int $target
     * @return int[]
     */
    function twoSum($nums, $target) {
        /**
         * @var array<int, int> Number to index map.
         */
        $indexMap = [];

        foreach ($nums as $index => $num) {
            $expectNum = $target - $num;

            if (array_key_exists($expectNum, $indexMap)) {
                return [$indexMap[$expectNum], $index];
            }

            $indexMap[$num] = $index;
        }

        return [];
    }
}
