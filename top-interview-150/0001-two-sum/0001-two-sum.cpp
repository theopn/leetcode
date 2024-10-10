class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> complements; // key = nums[i] val = i
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (complements.count(complement) > 0) {
                return { complements[complement], i };
            }
            complements[nums[i]] = i;
        }
        
        return { -1, -1 };
    }
};