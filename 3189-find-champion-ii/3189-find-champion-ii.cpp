class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n, 0);
        for (auto edge : edges) {
            indeg[edge[1]]++;
        }

        int champ = -1;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                if (champ != -1) return -1;
                champ = i;
            }
        }

        return champ;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();