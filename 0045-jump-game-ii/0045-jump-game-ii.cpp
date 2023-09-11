class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp{ nums[0] };
        for (int i = 1; i < nums.size(); i++) {
            dp.push_back(max(i + nums[i], dp[i - 1]));
        }

        int jumps = 0;
        int idx = 0;
        while (idx < nums.size() - 1) {
            jumps++;
            idx = dp[idx];
        }

        return jumps;
    }
};