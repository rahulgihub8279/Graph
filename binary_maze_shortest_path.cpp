// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> destination) {
        int n=grid.size();
        int m=grid[0].size();
        if (grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0)
            return -1;
        if (source == destination) 
            return 0;
        
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        vector<int>dr={-1,0,1,0};
        vector<int>dc={0,1,0,-1};
        queue<pair<int,pair<int,int>>>q;
        
        q.push({0,{source.first,source.second}});
        dist[source.first][source.second]=0;
        
        while(!q.empty()){
            auto it=q.front();
            q.pop(); 
            int d=it.first;
            int r=it.second.first;
            int c=it.second.second;
            
            for(int i=0; i<4; i++){
                int nr=dr[i]+r;
                int nc=dc[i]+c;
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && dist[nr][nc]>d+1){
                    if(nr==destination.first && nc==destination.second)
                        return d+1;
                    q.push({d+1,{nr,nc}});
                    dist[nr][nc]=d+1;
                }
            }
        }
        return -1;
        
    }
};
