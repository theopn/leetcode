class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) { return false; }
        
        unordered_map<char, char> pairs{
            { '(', ')' },
            { '{', '}' },
            { '[', ']' },
        };
        stack<char> st;
        
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else { // Make it else if checking for )}] if string contains other char
                if (st.empty()) { return false; }
                char opening = st.top();
                st.pop();
                if (c != pairs[opening]) {
                    return false;
                }
            }
        }
        
        return ((st.empty()) ? (true) : (false));
    }
};