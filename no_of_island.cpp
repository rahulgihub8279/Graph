class Solution {
public:
    void bfs(vector<vector<char>>& grid,vector<vector<int>>&visited,int row,int col){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        visited[row][col]=1;
        
        vector<int>dr={-1,0,1,0};
        vector<int>dc={0,1,0,-1};

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc] && grid[nr][nc]=='1'){
                    q.push({nr,nc});
                    visited[nr][nc]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    bfs(grid,visited,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};