class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> val_to_idx;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (val_to_idx.count(complement) != 0) {
                return { i, val_to_idx[complement] };
            }
            val_to_idx[nums[i]] = i;;
        }
        return { -1, -1 };
    }
};