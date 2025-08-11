class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        vector<int>dr={-1,0,1,0};
        vector<int>dc={0,1,0,-1};
        
        // row bounary
        for(int i=0; i<m; i++){
            if(grid[0][i]==1 && !visited[0][i]){
                q.push({0,i});
                visited[0][i]=1;
            }
            if(grid[n-1][i]==1 && !visited[n-1][i]){
                q.push({n-1,i});
                visited[n-1][i]=1;
            }
        }
        // col boundry
        for(int i=0; i<n; i++){
            if(grid[i][0]==1 && !visited[i][0]){
                q.push({i,0});
                visited[i][0]=1;
            }
            if(grid[i][m-1]==1 && !visited[i][m-1]){
                q.push({i,m-1});
                visited[i][m-1]=1;
            }
        }
        
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc] && grid[nr][nc]==1){
                    q.push({nr,nc});
                    visited[nr][nc]=1;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j]==1)
                    count++;
            }
        }
        return count;
    }
};