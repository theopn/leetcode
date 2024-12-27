class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        // before sorting, save the original index
        unordered_map<int, int> originalIdx;
        for (int i = 0; i < n; i++) {
            originalIdx[times[i][0]] = i;
        }
        sort(times.begin(), times.end());

        // make a min-heap for available seats
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; i++) {
            available.push(i);
        }

        // make a min-heap for (the time the chair becomes available, seat number)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupied;
        for (int i = 0; i < n; i++) {
            int currentArrival = times[i][0];
            int currentDeparture = times[i][1];

            // See if any chair becomes available
            while (!occupied.empty() && occupied.top().first <= currentArrival) {
                available.push(occupied.top().second);
                occupied.pop();
            }

            // assing a chair to the current person
            int assignedChair = available.top();
            available.pop();
            occupied.push({currentDeparture, assignedChair});

            // we found the person!
            if (originalIdx[currentArrival] == targetFriend) {
                return assignedChair;
            }
        }

        return -1; // should not happen
    }
};