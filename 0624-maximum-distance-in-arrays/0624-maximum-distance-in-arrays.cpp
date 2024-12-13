class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int currMin = arrays[0][0], currMax = arrays[0][arrays[0].size() - 1];

        int maxDist = 0;
        for (int i = 1; i < arrays.size(); i++) {
            int candidateOne = currMax - arrays[i][0];
            int candidateTwo = arrays[i][arrays[i].size() - 1] - currMin;
            int candidateFinal = max(candidateOne, candidateTwo);

            maxDist = max(maxDist, candidateFinal);

            currMin = min(currMin, arrays[i][0]);
            currMax = max(currMax, arrays[i][arrays[i].size() - 1]);
        }

        return maxDist;
    }
};