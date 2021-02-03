<?php
/**
 * https://leetcode.com/problems/add-two-numbers/
 */

/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val = 0, $next = null) {
 *         $this->val = $val;
 *         $this->next = $next;
 *     }
 * }
 */
class Solution {

    /**
     * @param ListNode $l1
     * @param ListNode $l2
     * @return ListNode
     */
    function addTwoNumbers($l1, $l2) {
        if ($l1 === null) {
            return $l2;
        }
        
        if ($l2 === null) {
            return $l1;
        }

        $rst = $this->addFirstNumbers($l1, $l2);
        
        if ($l1->next === null && $l2->next === null) {
            return $rst;
        }
        
        if ($l1->next === null) {
            $rst->next = $this->addTwoNumbers($l2->next, $rst->next);
            return $rst;
        }
        
        if ($l2->next === null) {
            $rst->next = $this->addTwoNumbers($l1->next, $rst->next);
            return $rst;
        }
        
        $rst->next = $this->addTwoNumbers($l1->next, $this->addTwoNumbers($l2->next, $rst->next));
        return $rst;
    }
    
    /**
     * @param ListNode $l1
     * @param ListNode $l2
     * @return ListNode
     */
    private function addFirstNumbers($l1, $l2) {
        $rst = new ListNode();
        $sum = $l1->val + $l2->val;
        $rst->val = $sum % 10;
        $carry = (int) ($sum / 10);
        if ($carry > 0) {
            $rst->next = new ListNode($carry);
        }
        return $rst;
    }
}
