class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n=grid.size(); 
        int m=grid[0].size(); 
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<int>>distance(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        
        while(!q.empty()){
            int r=q.front().first.first;   
            int c=q.front().first.second;   
            int dist=q.front().second;   
            vector<int>dr={-1,0,1,0};
            vector<int>dc={0,1,0,-1};
            q.pop();
            
            distance[r][c]=dist;
            for(int i=0; i<4; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc]){
                    visited[nr][nc]=1;
                    q.push({{nr,nc},dist+1});
                }
            }
        }
        return distance;
    }
};