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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> valToNode;
        unordered_map<int, bool> isChild;

        for (const auto& description : descriptions) {
            // Initialize a node
            int parent = description[0];
            TreeNode* node = valToNode[parent];
            if (!node) {
                node = new TreeNode(parent);
                valToNode[parent] = node;
            }

            // Get the child
            int child = description[1];
            int isLeft = description[2];
            TreeNode* childNode = valToNode[child];
            if (!childNode) {
                childNode = new TreeNode(child);
                valToNode[child] = childNode;
            }

            // Set the child
            if (isLeft) {
                node->left = childNode;
            } else {
                node->right= childNode;
            }

            // If the value appears as a child in the descriptions, it ain't the root
            isChild[child] = true;
        }

        // Find the non-child node from the isChild hashmap
        for (const auto& description : descriptions) {
            int parent = description[0];
            if (isChild[parent] == false) {
                return valToNode[parent];
            }
        }
        return nullptr;
    }
};