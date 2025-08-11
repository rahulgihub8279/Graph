class Solution {
public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] != 1e9 && dist[via][j] != 1e9) {
                        dist[i][j] = min(dist[i][via] + dist[via][j], dist[i][j]);
                    }
                }
            }
        }
        int ans = -1, maxcity = n;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold)
                    cnt++;
            }
            if (cnt <= maxcity) {
                maxcity = cnt;
                ans = i;
            }
        }
        return ans;
    }
};
