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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Version using sentinel
        unordered_set<int> numset(nums.begin(), nums.end());

        ListNode* sentinel = new ListNode();
        sentinel->next = head;

        ListNode* curr = sentinel;
        while (curr->next != nullptr) {
            if (numset.contains(curr->next->val)) {
                ListNode* tmp = curr->next;
                curr->next = curr->next->next;
                delete tmp;
            } else {
                curr = curr->next;
            }
        }

        return sentinel->next;
    }
};