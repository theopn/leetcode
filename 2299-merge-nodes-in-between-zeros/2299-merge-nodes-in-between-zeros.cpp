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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* traverse = head->next;
        ListNode* tobemodified = head->next;

        while (traverse) {
            // Sum until the next zero node
            int curr_sum = 0;
            while (traverse->val != 0) {
                curr_sum += traverse->val;
                traverse = traverse->next;
            }
            // Advance one up so that traverse becomes the next non-zero node
            traverse = traverse->next;

            // Modify the value
            tobemodified->val = curr_sum;
            // Set the tobemodified to the next non-zero node
            tobemodified->next = traverse;
            tobemodified = tobemodified->next;
        }

        return head->next;
    }
};