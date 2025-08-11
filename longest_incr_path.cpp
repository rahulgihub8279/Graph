class Solution
{
public:
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &memo, int r, int c)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        if (memo[r][c] != -1)
            return memo[r][c];
            
        int maxlen = 1;
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && matrix[nr][nc] > matrix[r][c])
            {
                maxlen = max(maxlen, 1 + dfs(matrix, memo, nr, nc));
            }
        }
        memo[r][c] = maxlen;
        return maxlen;
    }
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        int maxpath = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                maxpath = max(maxpath, dfs(matrix, memo, i, j));
            }
        }
        return maxpath;
    }
};