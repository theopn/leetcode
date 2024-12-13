class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> count;
        for (auto str : arr) {
            count[str]++;
        }

        int j = 0;
        for (auto str : arr) {
            if (count[str] == 1) {
                j++;
                if (j == k) return str;
            }
        }
        return "";
    }
};