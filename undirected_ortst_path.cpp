class Solution {
  public: 
    vector<int> shortestPath(vector<vector<int>>& adj, int src) { 
        int n=adj.size();
        vector<int>dist(n,1e9);
        dist[src]=0;
        queue<pair<int,int>>q;
        q.push({src,0});
        
        while(!q.empty()){
            int node=q.front().first;
            int d=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(d+1<dist[it]){
                    dist[it]=d+1;
                    q.push({it,d+1});
                }
            }
        }
        for(int i=0; i<n; i++){
            if(dist[i]==1e9) dist[i]=-1;
        }
        return dist;
    }
};