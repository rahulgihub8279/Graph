class Solution {
  public:
    void solve(vector<vector<int>>& adj,vector<int>&visited,vector<int>&path,int node){
        visited[node]=1;
        path.push_back(node);
        for(auto i:adj[node]){
            if(!visited[i])
                solve(adj,visited,path,i);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int vertices=adj.size();
        int start=0;
        vector<int>visited(vertices,0);
        vector<int>path;
        solve(adj,visited,path,start);
        return path;
    }
};