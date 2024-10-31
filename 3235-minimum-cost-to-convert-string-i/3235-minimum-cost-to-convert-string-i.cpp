class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int v = 26; // number of vertices
        int e = original.size(); // number of edges

        // builds a 26x26 adjacency matrix
        vector<vector<long>> dist(v, vector<long>(v, INT_MAX));
        for (int i = 0; i < e; i++) {
            int o = original[i] - 97;
            int c = changed[i] - 97;
            // Edge case 1: "a -> b costs 2" ... "a -> b costs 3" -> keep the minimum cost
            if (dist[o][c] > cost[i]) {
                dist[o][c] = cost[i];
            }
        }

        // Edge case 2: "a -> a costs 100" -> set cost of converting the same char (i.e., not converting) to 0
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (i == j) dist[i][j] = 0;
            }
        }

        // Floyd=Warshall
        for (int k = 0; k < v; k++) {
            for (int i = 0; i < v; i++) {
                for (int j = 0; j < v; j++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Iterate through char in source and sum the cost of conversion
        long long total = 0;
        for (int i = 0; i < source.size(); i++) {
            int s = source[i] - 97;
            int t = target[i] - 97;
            // not convertible
            if (dist[s][t] == INT_MAX) return -1;
            total += dist[s][t];
        }

        return total;
    }
};