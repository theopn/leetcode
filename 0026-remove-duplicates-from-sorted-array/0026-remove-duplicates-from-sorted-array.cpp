class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1;
        for (auto num : nums) {
            if (num != nums[i - 1]) {
                nums[i] = num;
                i++;
            }
        }
        return i;
    }
};