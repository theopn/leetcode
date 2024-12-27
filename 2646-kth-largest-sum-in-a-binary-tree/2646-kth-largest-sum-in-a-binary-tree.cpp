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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;

        priority_queue<long> levelSums;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            long levelSum = 0;
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();
                levelSum += curr->val;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            levelSums.push(levelSum);
        }

        // Return kth element
        if (levelSums.size() < k) return -1;
        for (int i = 0; i < k - 1; i++) {
            levelSums.pop();
        }
        return levelSums.top();
    }
};