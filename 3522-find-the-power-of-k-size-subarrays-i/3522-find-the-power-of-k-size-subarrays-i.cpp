class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> results(n - k + 1, -1);

        int head = 0;
        for (int head = 0; head + k - 1 < n; head++) {
            bool consecutive = true;
            for (int i = 1; i < k; i++) {
                if (nums[head + i] != nums[head + i - 1] + 1) {
                    consecutive = false;
                    break;
                }
            }

            if (consecutive) {
                results[head] = nums[head + k - 1];
            }
        }

        return results;
    }
};