void bfs(vector<vector<int>> &adj,vector<int>&visited, vector<int>&ans,int vertex){
    queue<int>q;
    q.push(vertex);
    visited[vertex]=1;
    while(!q.empty()){
        int fnode=q.front();
        q.pop();
        ans.push_back(fnode);
        for(int i=0; i<adj[fnode].size(); i++){
            int val=adj[fnode][i];
            if(!visited[val]){
                q.push(val);
                visited[val]=1;
            }    
        }

    }
}
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int>ans;
    vector<int>visited(n,0);
    bfs(adj,visited,ans,0);
    return ans;
}