/**
 * Idea:
 * 1.  head -> node2
 * 2.  node1 -> swapPairs(node3) (recursively handle the list headed by node3)
 * 3.  node2 -> node1
 *
 * Time Complexity: Θ(n), where n is the list length.
 * Space Complexity: Θ(n), where n is the list length. (because of recursion)
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* node1 = head;
        head = node1->next;
        node1->next = swapPairs(head->next);
        head->next = node1;

        return head;
    }
};
