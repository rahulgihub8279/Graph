int dfs(int node,int parent,vector<vector<int> >&adj,vector<int>&visited){
    visited[node]=1;
    for(auto adj_node:adj[node]){
        if(!visited[adj_node]){
            if(dfs(adj_node,node,adj,visited)){
              return 1;  
            } 
        }
        else if(adj_node!=parent){
            return 1;
        }
    }
    return 0;
    
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>>adj(A);
    vector<int>visited(A,0);
    for(auto it:B){
        int u=it[0]-1,v=it[1]-1;
        adj[u].push_back(v);
        adj[v].push_back(u);    
    }
    for(int i=0; i<A; i++){
        if(!visited[i]){
            if(dfs(i,-1,adj,visited)) return 1;
        }
    }
    return 0;
}
