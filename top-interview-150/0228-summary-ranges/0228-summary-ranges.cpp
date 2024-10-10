class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for (int i = 0; i < nums.size(); i++) {
            int head = nums[i];
            while ((i + 1 < nums.size()) &&
                    (nums[i + 1] == nums[i] + 1)) {
                i++;
            }

            string res;
            if (head == nums[i]) {
                res = to_string(head);
            } else {
                res = to_string(head) + "->" + to_string(nums[i]);
            }
            ans.push_back(res);
        }

        return ans;
    }
};