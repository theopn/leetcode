class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> allowedmap(26, false);
        for (auto c : allowed) {
            allowedmap[c - 96] = true;
        }

        int count = 0;
        for (auto word : words) {
            bool consistent = true;
            for (auto c : word) {
                if (!allowedmap[c - 96]) {
                    consistent = false;
                    break;
                }
            }
            if (consistent) count++;
        }

        return count;
    }
};