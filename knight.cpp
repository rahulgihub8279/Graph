class Solution
{
public:
    int minStepToReachTarget(vector<int> &knightPos, vector<int> &targetPos, int n)
    {
        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        int startX = knightPos[0] - 1;
        int startY = knightPos[1] - 1;
        int targetX = targetPos[0] - 1;
        int targetY = targetPos[1] - 1;

        if (startX == targetX && startY == targetY)
            return 0;

        q.push({{startX, startY}, 0});
        vector<int> delr = {1, 2, 2, 1, -1, -2, -2, -1};
        vector<int> delc = {2, 1, -1, -2, -2, -1, 1, 2};

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int dist = it.second;

            for (int i = 0; i < 8; i++)
            {
                int nr = r + delr[i];
                int nc = c + delc[i];
                if (nr == targetX && nc == targetY)
                    return dist + 1;
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc])
                {
                    visited[nr][nc] = 1;
                    q.push({{nr, nc}, dist + 1});
                }
            }
        }
        return -1;
    }
};