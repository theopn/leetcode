class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size(); // Case: k >= nums.size()
        reverse(nums.begin(), nums.end()); // Rotate whole array
        reverse(nums.begin() + k, nums.end()); // Rotate [k, n)
        reverse(nums.begin(), nums.begin() + k); // Rotate [0, k)
    }
};