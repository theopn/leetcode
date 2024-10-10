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
    void inorder(TreeNode* root, vector<int>& val) {
        if (!root) return;
        inorder(root->left, val);
        val.push_back(root->val);
        inorder(root->right, val);
    }

    TreeNode* buildBalancedBSTFromSortedArr(vector<int>& arr, int start, int end) {
        if (start > end) return NULL;

        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = buildBalancedBSTFromSortedArr(arr, start, mid - 1);
        root->right = buildBalancedBSTFromSortedArr(arr, mid + 1, end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> traversal;
        inorder(root, traversal);
        return buildBalancedBSTFromSortedArr(traversal, 0, traversal.size() - 1);
    }
};