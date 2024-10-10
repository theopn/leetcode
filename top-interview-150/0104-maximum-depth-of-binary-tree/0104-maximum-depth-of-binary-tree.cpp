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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if (root == NULL) { return depth; }
        
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            depth++;

            int save = q.size();
            for (int i = 0; i < save; i++) { // Adjacent to current node
                TreeNode *curr = q.front();
                q.pop();

                if (curr->left) { q.push(curr->left); }
                if (curr->right) { q.push(curr->right); }
            }
        }

        return depth;
    }
};