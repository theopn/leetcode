class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // Find the max in arr1 and make the count arr
        int m = 0;
        for (auto num : arr1) {
            m = max(m, num);
        }

        // Get the count
        vector<int> count(m + 1, 0);
        for (auto num : arr1) {
            count[num]++;
        }

        // Instead of prefix sum, we use the arr2 to populate the first arr2.size() elements
        vector<int> out(arr1.size());
        int idx = 0;
        for (auto num : arr2) {
            while (count[num]-- > 0) {
                out[idx++] = num;
            }
        }

        // Populate rest of the elements
        for (int i = 0; i <= m; i++) {
            while (count[i]-- > 0) {
                out[idx++] = i;
            }
        }

        return out;
    }
};