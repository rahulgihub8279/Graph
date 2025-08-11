class Solution
{
public:
    int dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int r, int c)
    {
        vis[r][c] = 1;
        int area = 1;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        for (int i = 0; i <= 3; i++)
        {
            int nr = dr[i] + r;
            int nc = dc[i] + c;
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1)
                area += dfs(grid, vis, nr, nc);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int maxArea = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    int currArea = dfs(grid, visited, i, j);
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        return maxArea;
    }
};