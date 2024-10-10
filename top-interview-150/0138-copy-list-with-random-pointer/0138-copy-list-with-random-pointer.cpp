/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *ans = new Node(420); // Dummy node
        unordered_map<Node*, Node*> hash;

        Node *ans_cpy = ans;
        Node *head_cpy = head;
        while (head) {
            ans->next = new Node(head->val);
            ans = ans->next;
            hash[head] = ans;
            head = head->next;
        }

        head = head_cpy; // restore
        ans = ans_cpy->next;   // ^
        while (head) {
            ans->random = hash[head->random];
            ans = ans->next;
            head = head->next;
        }

        return ans_cpy->next;
    }
};