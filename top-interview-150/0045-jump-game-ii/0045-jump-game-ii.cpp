class Solution {
public:
    int jump(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = max(i + nums[i], nums[i - 1]);
        }

        int jumps = 0;
        int idx = 0;
        while (idx < nums.size() - 1) {
            jumps++;
            idx = nums[idx];
        }

        return jumps;
    }
};