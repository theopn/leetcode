class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        vector<int> copy(arr.begin(), arr.end());
        sort(copy.begin(), copy.end());
        unordered_map<int, int> map;
        int rank = 1;
        for (auto num : copy) {
            if (map[num] == 0) {
                map[num] = rank;
                rank++;
            }
        }

        vector<int> ranks(n);
        for (int i = 0; i < n; i++) {
            ranks[i] = map[arr[i]];
        }

        return ranks;
    }
};