/**
 * Idea:
 * 1. Index of the target to be removed is `size - n`.
 * 2. Use a pointer as an end probe, and forward it for `n` times.
 * 3. If `n == size`, the end probe will be nullptr now. Then, we can remove
 *    the head and return the next node of original head as the new head.
 * 4. Else, forward the end probe and target pointer together until the end
 *    probe arrives the end (= nullptr), and the target pointer will point to
 *    the node to be removed. Totally, the end probe was moved `size` times, and
 *    the target pointer was moved `size - n` times.
 *
 * Time Complexity: Θ(n), where n is the size of input list
 * Space Complexity: Θ(1)
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* end_probe = head;
        ListNode* target = head;

        while (n--) {
            end_probe = end_probe->next;
        }

        // condition: n = size
        if (!end_probe) {
            head = head->next;
            delete target;

            return head;
        }

        while (end_probe->next) {
            end_probe = end_probe->next;
            target = target->next;
        }

        // index of `end_probe` = size - 1, index of `previous` = size - 1 - n
        ListNode* previous = target;
        // index of `target` = size - n
        target = target->next;
        previous->next = target->next;
        delete target;

        return head;
    }
};
