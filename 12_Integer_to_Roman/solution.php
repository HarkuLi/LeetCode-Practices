<?php
/**
 * https://leetcode.com/problems/integer-to-roman/
 */

class Solution {
    private const ROMAN_TABLE = [
        [
            [
                'sign' => 'CM',
                'value' => 900,
            ],
            [
                'sign' => 'D',
                'value' => 500,
            ],
            [
                'sign' => 'CD',
                'value' => 400,
            ],
            [
                'sign' => 'C',
                'value' => 100,
            ],
        ],
        [
            [
                'sign' => 'XC',
                'value' => 90,
            ],
            [
                'sign' => 'L',
                'value' => 50,
            ],
            [
                'sign' => 'XL',
                'value' => 40,
            ],
            [
                'sign' => 'X',
                'value' => 10,
            ],
        ],
        [
            [
                'sign' => 'IX',
                'value' => 9,
            ],
            [
                'sign' => 'V',
                'value' => 5,
            ],
            [
                'sign' => 'IV',
                'value' => 4,
            ],
            [
                'sign' => 'I',
                'value' => 1,
            ],
        ],
    ];
    
    /**
     * @param Integer $num
     * @return String
     */
    function intToRoman($num) {
        $rst = '';
        
        $remainder = $num;
        $quotient = (int) ($remainder / 1000);
        if ($quotient > 0) {
            $rst .= str_repeat('M', $quotient);
            $remainder %= 1000;
        }
        
        foreach (self::ROMAN_TABLE as $signGroup) {
            if ($remainder >= $signGroup[0]['value']) {
                $rst .= $signGroup[0]['sign'];
                $remainder -= $signGroup[0]['value'];
            } else if ($remainder >= $signGroup[1]['value']) {
                $rst .= $signGroup[1]['sign'];
                $remainder -= $signGroup[1]['value'];
            } else if ($remainder >= $signGroup[2]['value']) {
                $rst .= $signGroup[2]['sign'];
                $remainder -= $signGroup[2]['value'];
            }
            
            $quotient = (int) ($remainder / $signGroup[3]['value']);
            if ($quotient > 0) {
                $rst .= str_repeat($signGroup[3]['sign'], $quotient);
                $remainder %= $signGroup[3]['value'];
            }
        }
        
        return $rst;
    }
}
