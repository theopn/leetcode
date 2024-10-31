class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto num : nums) {
            freq[num]++;
        }
        auto comparator = [&freq](int a, int b) { 
            return freq[a] == freq[b] ? (a > b) : (freq[a] < freq[b]);
        }; 
        sort(nums.begin(), nums.end(), comparator);
        return nums;
    }
};