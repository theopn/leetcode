class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        s += s;
        for (int i = 0; i < s.size() - goal.size(); i++) {
            for (int j = 0; j < goal.size(); j++) {
                if (s[i + j] != goal[j]) {
                    break;
                }
                if (j == goal.size() - 1) {
                    return true;
                }
            }
        }

        return false;
    }
};