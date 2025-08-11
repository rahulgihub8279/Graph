class Solution {
  public:
    bool dfs(int node, vector<int>&visited, vector<int>&pathVisited,unordered_map<int,vector<int>>&adjlist){
        visited[node]=1;
        pathVisited[node]=1;
        for(int adjnode:adjlist[node]){
            if(!visited[adjnode]){
                if(dfs(adjnode,visited,pathVisited,adjlist))
                    return true;
            }
            else if(pathVisited[adjnode])
                return true;
        }
        pathVisited[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int>visited(V,0);
        vector<int>pathVisited(V,0);
        unordered_map<int,vector<int>>adjlist;
        
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adjlist[u].push_back(v);
        }
        
        for(int i=0 ; i<V; i++){
            if(!visited[i]){
                if(dfs(i,visited,pathVisited,adjlist))
                    return true;
            }
        }
        return false;
    }
};