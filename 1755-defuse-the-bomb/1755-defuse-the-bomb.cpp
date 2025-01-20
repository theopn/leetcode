class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();

        vector<int> decrypted(n, 0);

        if (k > 0) {
            for (int i = 0; i < n; i++) {
                int number = 0;
                for (int j = 1; j <= k; j++) {
                    number += code[(i + j) % n];
                }
                decrypted[i] = number;
            }
        } else if (k < 0) {
            for (int i = 0; i < n; i++) {
                int number = 0;
                for (int j = 1; j <= -k; j++) {
                    number += code[(((i - j) % n) + n) % n];
                }
                decrypted[i] = number;
            }
        }

        return decrypted;
    }
};