/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void postorderHelper(Node* node, vector<int>& traversal) {
        if (!node) return;

        for (auto children : node->children) {
            postorderHelper(children, traversal);
        }
        traversal.push_back(node->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> traversal;
        postorderHelper(root, traversal);
        return traversal;
    }
};