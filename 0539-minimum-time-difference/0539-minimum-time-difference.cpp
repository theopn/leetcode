class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();

        vector<int> timeinmin(n);
        for (int i = 0; i < n; i++) {
            int hour = stoi(timePoints[i].substr(0, 2));
            int minute= stoi(timePoints[i].substr(3, 5));
            timeinmin[i] = hour * 60 + minute;
        }

        sort(timeinmin.begin(), timeinmin.end());

        int smallestConsecutiveDiff = INT_MAX;
        for (int i = 1; i < n; i++) {
            smallestConsecutiveDiff = min(smallestConsecutiveDiff, timeinmin[i] - timeinmin[i - 1]);
        }

        int circularDiff = 1440 - abs(timeinmin[n - 1] - timeinmin[0]); // 24 * 60 = 1440

        return min(circularDiff, smallestConsecutiveDiff);
    }
};