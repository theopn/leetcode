class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= curr) { curr = i; }
        }
        return (curr == 0);
    }
};