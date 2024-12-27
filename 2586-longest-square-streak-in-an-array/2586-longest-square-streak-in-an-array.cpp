class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // add every elements to set
        unordered_set<int> numset(nums.begin(), nums.end());

        int longest = 0;
        for (auto num : nums) {
            // set the current num as the starting point
            long curr = num;
            // increment length until we cannot find the square in the set
            int length = 0;
            while (numset.find(curr) != numset.end()) {
                length++;
                // move to the next square
                curr *= curr;
                // handle the overflow
                if (curr > 1e5) break;
            }
            longest = max(longest, length);
        }

        // return -1 if the length of the steak is less than 2
        return (longest == 1) ? -1 : longest;
    }
};