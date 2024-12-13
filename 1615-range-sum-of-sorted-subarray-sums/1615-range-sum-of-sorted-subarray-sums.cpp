class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {

        vector<int> subarrSums; // size n * (n + 1) / 2
        for (int i = 0; i < n; i++) {
            int currSum = 0;
            for (int j = i; j < n; j++) {
                currSum += nums[j];
                subarrSums.push_back(currSum);
            }
        }

        sort(subarrSums.begin(), subarrSums.end());

        int m = 1e9 + 7;
        int ans = 0;
        for (int i = left - 1; i < right; i++) {
            ans = (ans + subarrSums[i]) % m;
        }

        return ans;
    }
};