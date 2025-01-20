class Solution {
public:

    // returns true if you can distribute all products such that any store will not be given more than k products
    bool canDistribute(int k, int n, vector<int>& quantities) {
        int idx = 0;
        int rem = quantities[idx];
        for (int store = 0; store < n; store++) {
            if (rem <= k) {
                idx++;
                if (idx >= quantities.size()) {
                    return true;
                }
                rem = quantities[idx];
            } else {
                rem -= k;
            }
        }
        return rem == 0;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo = 0;
        int hi = INT_MIN;
        for (auto quantity : quantities) {
            hi = max(hi, quantity);
        }

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            bool can = canDistribute(mid, n, quantities);

            if (!can) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};