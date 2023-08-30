class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1;
        int curr_num = nums[0];
        for (auto num : nums) {
            if (num != curr_num) {
                nums[i] = num;
                curr_num = num;
                i++;
            }
        }
        return i;
    }
};