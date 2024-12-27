class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxx = 0, maxlen = 0, curlen = 0;
        for (auto num : nums) {
            if (num > maxx) {
                maxx = num;
                curlen = 0;
                maxlen = 0;
            }

            if (maxx == num) {
                curlen++;
                maxlen = max(maxlen, curlen);
            } else {
                curlen = 0;
            }
        }
        return maxlen;
    }
};