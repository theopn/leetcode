class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;

        int num = 0;
        for (auto c : s) {
            if (c == '[') {
                st.push(c);
            } else { // c == ']'
                if (!st.empty()) {
                    st.pop();
                } else {
                    num++;
                }
            }
        }

        return (num + 1) / 2;
    }
};