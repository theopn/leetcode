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
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* node = head;
        while (node && node->next) {
            int gcdd = gcd(node->val, node->next->val);
            //cout << "gcd b/w node: " << node->val << " and node->next: " << node->next->val << "  is: " << gcdd << endl;
            ListNode* gcdNode = new ListNode(gcdd);
            gcdNode->next = node->next;
            node->next = gcdNode;

            node = gcdNode->next;
        }
        
        return head;
    }
};