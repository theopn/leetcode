class Solution {
public:
    int minLength(string s) {
        stack<int> st;

        for (int i = 0; i < s.size(); i++) {
            if (st.empty()) {
                st.push(s[i]);
                continue;
            }

            char top = st.top();
            if ((top == 'A' && s[i] == 'B') || (top == 'C' && s[i] == 'D')) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        return st.size();
    }
};