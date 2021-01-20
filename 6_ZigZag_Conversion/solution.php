<?php
/**
 * https://leetcode.com/problems/zigzag-conversion/
 */

class Solution {
    /**
     * @param String $s
     * @param Integer $numRows
     * @return String
     */
    function convert($s, $numRows) {
        if ($numRows === 1 || $numRows >= strlen($s)) {
            return $s;
        }
        
        // format: [row => [char1, char2, ...]]
        $rowBuffers = [];
        for ($i = 0; $i < $numRows; ++$i) {
            $rowBuffers[$i] = [];
        }
        
        $lastRow = -1;
        $currentRow = 0;
        $strLen = strlen($s);
        for ($i = 0; $i < $strLen; ++$i) {
            $char = $s[$i];
            $rowBuffers[$currentRow][] = $char;
            
            $nextRow = $this->getNextRow($lastRow, $currentRow, $numRows);
            $lastRow = $currentRow;
            $currentRow = $nextRow;
        }
        
        return array_reduce(
            $rowBuffers,
            function ($str, $charList) {
                return $str . implode($charList);
            },
            ""
        );
    }

    /**
     * @param Integer $currentRow
     * @param Integer $numRows
     * @return Integer Next row.
     */
    private function getNextRow($lastRow, $currentRow, $numRows) {
        if ($numRows === 1) {
            return 0;
        }
        
        if ($currentRow === 0) {
            return $currentRow + 1;
        }
        
        if ($currentRow === $numRows - 1) {
            return $currentRow - 1;
        }
        
        return $currentRow > $lastRow ? $currentRow + 1 : $currentRow - 1;
    }
}
