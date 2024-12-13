class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // makes adjacency list with destination-probability pair
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double w = succProb[i];
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }

        // Dijkstra but:
        // 1. finding the longest "distance" so use max-heap and flip relaxation conditions
        // 2. the "distance" is actually probability
        vector<double> prob(n, 0.0);
        priority_queue<pair<double, int>> q;
        prob[start_node] = 1.0;
        q.push(make_pair(1.0, start_node));

        while (!q.empty()) {
            auto [p, u] = q.top();
            q.pop();

            if (p == prob[u]) {
                for (auto [v, w] : adj[u]) {
                    // calculates candidate probability
                    double candidate;
                    if (prob[u] == 1.0 || prob[u] == 0.0) {
                        candidate = w;
                    } else {
                        candidate = prob[u] * w;
                    }

                    // reverse relaxation condition
                    if (candidate > prob[v]) {
                        prob[v] = candidate;
                        q.push(make_pair(candidate, v));
                    }
                }
            }
        }

        // if not reachable, it will have 0.0
        return prob[end_node];
    }
};