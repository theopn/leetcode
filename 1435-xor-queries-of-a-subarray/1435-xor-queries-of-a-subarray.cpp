class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto querie : queries) {
            int left = querie[0], right = querie[1];

            int res = 0;
            for (int i = left; i <= right; i++) {
                res ^= arr[i];
            }

            ans.push_back(res);
        }

        return ans;
    }
};