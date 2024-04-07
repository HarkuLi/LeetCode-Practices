/**
 * Idea:
 * 1. If one of input lists is null, return the other one.
 * 2. Choose the list with smaller head as base, and merge its remaining list
 *    and the other list as its new "next".
 *
 * Time Complexity: Θ(n), where n is the minimum length among list1 and list2.
 * Space Complexity:
 * 1. Θ(n), where n is the minimum length among list1 and list2.
 * 2. Θ(1), if tail-call optimization is supported.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }

        if (list2 == nullptr) {
            return list1;
        }

        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
