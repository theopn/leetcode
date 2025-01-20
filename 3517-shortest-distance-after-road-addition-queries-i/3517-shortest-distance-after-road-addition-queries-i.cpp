class Solution {
public:
    int bfs(int n, vector<vector<int>> adj) {
        queue<int> q;
        vector<int> dist(n, -1);
        //vector<int> parents(n, -1);

        q.push(0);
        dist[0] = 0;
        //parents[0] = -1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto node : adj[u]) {
                if (dist[node] == -1) {
                    dist[node] = dist[u] + 1;
                    //parents[node] = u;
                    q.push(node);
                }
            }
        }

        return dist[n - 1];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);

        // add initial road
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        vector<int> out(queries.size(), -1);
        // add additional road
        for (int i = 0; i < queries.size(); i++) {
            adj[queries[i][0]].push_back(queries[i][1]);
            out[i] = bfs(n, adj);
        }

        return out;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();