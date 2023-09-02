class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true;
        if (s.size() > t.size()) return false;
        int ptr = 0; // Ptr for the char in s
        for (auto c : t) {
            if (c == s[ptr]) {
                ptr++;
                if (ptr >= s.size()) {
                    return true;
                }
            }
        }
        
        return false;
    }
};