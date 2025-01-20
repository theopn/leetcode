class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indeg;
        unordered_map<int, int> outdeg;

        for (auto pair : pairs) {
            int u = pair[0], v = pair[1];
            adj[u].push_back(v);
            indeg[v]++;
            outdeg[u]++;
        }

        // we can choose any vertex for using Hierholzer for finding a Euler Cycle. But in Euler Path,
        // one node has outdeg == indeg + 1 (starting) and one has indeg == outdeg + 1 (ending).
        // In the question, the graph might have an Euler Cycle, then we can choose any vertex
        int start = pairs[0][0]; // the any vertex in question
        for (auto [node, indegree] : outdeg) {
            if (outdeg[node] == indeg[node] + 1) {
                start = node;
                break;
            }
        }

        vector<int> path;
        stack<int> currpath;
        currpath.push(start);

        while (!currpath.empty()) {
            int node = currpath.top();
            // if we have more edge to travel from this node
            if (!adj[node].empty()) {
                currpath.push(adj[node].back());
                adj[node].pop_back();
            } else {
                // backtrack
                path.push_back(node);
                currpath.pop();
            }
        }

        reverse(path.begin(), path.end());

        // the path is in terms of vertices (e.g., [11, 9, 4, 5, 1])
        // convert it in terms of edges (e.g., [[11, 9], [9, 4], [4, 5], [5, 1]])
        vector<vector<int>> paired;
        for (int i = 1; i < path.size(); i++) {
            paired.push_back({ path[i - 1], path[i] });
        }

        return paired;
    }
};