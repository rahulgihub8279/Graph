
class Solution
{
public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minheap;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        dist[0][0] = 0;
        minheap.push({0, {0, 0}});

        while (!minheap.empty())
        {
            auto it = minheap.top();
            minheap.pop();
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == n - 1 && c == m - 1)
                return d;

            for (int i = 0; i <= 3; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m)
                {
                    int neweffort = max(d, abs(heights[r][c] - heights[nr][nc]));
                    if (neweffort < dist[nr][nc])
                    {
                        dist[nr][nc] = neweffort;
                        minheap.push({neweffort, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};
