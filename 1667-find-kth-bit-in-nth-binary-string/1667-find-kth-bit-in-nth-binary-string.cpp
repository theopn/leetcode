class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";

        for (int i = 1; i < n && s.size() < k; i++) {
            s += '1';
            string tmp = s;
            for (int j = tmp.size() - 2; j >= 0; j--) {
                s += (tmp[j] == '0') ? '1' : '0';
            }
        }

        return s[k - 1];
    }
};