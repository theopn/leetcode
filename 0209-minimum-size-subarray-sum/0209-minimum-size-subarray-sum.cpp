class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int head_pos = 0;
        int min_len = nums.size() + 69;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= target) {
                if (min_len > i + 1 - head_pos) {
                    min_len = i + 1 - head_pos;
                }
                sum -= nums[head_pos];
                head_pos++;
            }
        }
        
        return (min_len == nums.size() + 69) ? (0) : (min_len);
    }
};