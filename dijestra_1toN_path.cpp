class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) { 
        vector<vector<pair<int,int>>>adjlist(n+1);
        for(auto it:edges){
            adjlist[it[0]].push_back({it[1],it[2]});
            adjlist[it[1]].push_back({it[0],it[2]});
        }
        vector<int>dist(n+1,1e9);
        vector<int>parent(n+1,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        
        dist[1]=0;
        for(int i=1; i<=n; i++) parent[i]=i;
        
        minheap.push({0,1});
        while(!minheap.empty()){
            int node=minheap.top().second;        
            int d=minheap.top().first;        
            minheap.pop();
            for(auto it:adjlist[node]){
                int adjnode=it.first;            
                int wt=it.second;            
                if(d+wt<dist[adjnode]){
                    dist[adjnode]=d+wt;
                    parent[adjnode]=node;
                    minheap.push({d+wt,adjnode});
                }
            }   
        }    
        vector<int>path;
        if(dist[n]==1e9) return {-1};
    
        int node=n;
        while(parent[node]!=node){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(1);
        path.push_back(dist[n]);
        reverse(path.begin(),path.end());
        return path;
    }
};






