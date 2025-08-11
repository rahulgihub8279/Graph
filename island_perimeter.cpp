class Solution {
public:
    //* approach 1 
    int islandPerimeter(vector<vector<int>>& grid) {
        int peri=0;
        int n=grid.size();   
        int m=grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    if(j-1<0 || grid[i][j-1]==0) peri++;
                    if(i-1<0 || grid[i-1][j]==0) peri++;
                    if(j+1>=m || grid[i][j+1]==0) peri++;
                    if(i+1>=n || grid[i+1][j]==0) peri++;
                }
            }
        }   
        return peri;
    } 
    //* approach 2 
    void dfs(vector<vector<int>>& grid, int i, int j, int& peri) {
        int n = grid.size();
        int m = grid[0].size();
        grid[i][j] = -1;
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m || grid[nr][nc] == 0) {
                peri++;
            } else if (grid[nr][nc] == 1) {
                dfs(grid, nr, nc, peri);
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int peri = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, peri);
                    return peri;
                }
            }
        }
        return peri;
    }
};
