class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nums_cpy(nums.begin(), nums.end());
        
        int pos = -1;
        for (int i = 0; i < n; i++) {
            pos = (i + k) % n;
            nums[pos] = nums_cpy[i];
        }
    }
};