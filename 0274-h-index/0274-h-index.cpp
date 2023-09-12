class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::sort(citations.begin(), citations.end());
        int h = 0;
        int n = citations.size();
        for (int i = 0; i < n; i++) {
            int candidate = min(citations[i], n - i);
            if (h < candidate) {
                h = candidate;
            }
        }
        return h;
    }
};