class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int target = nums.size() / 2;
        std::unordered_map<int, int> hashbrown;
        for (auto num : nums) {
            hashbrown[num]++;
            if (hashbrown[num] > target) {
                return num;
            }
        }
        
        return -1;
    }
};