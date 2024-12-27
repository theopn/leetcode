class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;

        int openings = 0;
        int closings = 0;
        for (auto c : s) {
            if (c == '(') {
                openings++;
            } else {
                openings > 0 ? openings-- : closings++;
            }
        }

        return openings + closings;
    }
};