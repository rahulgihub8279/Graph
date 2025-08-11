class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        int time = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int ctime = q.front().second;
            q.pop();
            time = ctime;
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    !visited[nr][nc] && grid[nr][nc] == 1) {
                    q.push({{nr, nc}, ctime + 1});
                    visited[nr][nc] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j])
                    return -1;
            }
        }
        return time;
    }
};