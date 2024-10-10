class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int carry = 0;
        int a_pos = a.size() - 1;
        int b_pos = b.size() - 1;

        while (a_pos >= 0 || b_pos >= 0) {
            int a_val = a_pos >= 0 ? (a[a_pos] - '0') : 0;
            int b_val = b_pos >= 0 ? (b[b_pos] - '0') : 0;
            int sum = a_val + b_val + carry;

            if (sum > 1) {
                sum = sum % 2;
                carry = 1;
            } else {
                carry = 0;
            }
            ans.append(to_string(sum));
            a_pos--; b_pos--;
        }
        if (carry) ans.append("1");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};