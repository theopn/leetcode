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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool dfs(ListNode* lnode, TreeNode* tnode) {
        if (!lnode) return true;  // all nodes in the ll have been matched
        if (!tnode) return false; // reached the leaf of the tree

        if (lnode->val != tnode->val) return false;  // value mismatch
        return dfs(lnode->next, tnode->left) || dfs(lnode->next, tnode->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;

        if (dfs(head, root)) return true;
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};