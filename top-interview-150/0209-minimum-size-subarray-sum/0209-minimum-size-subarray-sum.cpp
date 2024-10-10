class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0; // Sum from the beginning to the current window tail
        int head_pos = 0; // Beginning of the "window"
        int min_len = nums.size() + 69; // If this val never changed, return 0
        
        for (int i = 0; i < nums.size(); i++) { // Let's slide the window
            sum += nums[i];
            
            // Move the head (shrink the window) while it meets the condition
            while (sum >= target) {
                // Update the min_len if the current window is smaller
                if (min_len > i + 1 - head_pos) {
                    min_len = i + 1 - head_pos;
                }
                // Remove the head from the window
                sum -= nums[head_pos];
                head_pos++;
            }
        }
        
        return (min_len == nums.size() + 69) ? (0) : (min_len);
    }
};