// User function Template for C++
class Solution {
  public:
    void dfs(int node,vector<int>&visited,vector<vector<pair<int,int>>>&adjlist,stack<int>&st){
        visited[node]=1;
        for(auto it:adjlist[node]){
            int v=it.first;
            if(!visited[v]){
                dfs(v,visited,adjlist,st);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) { 
        vector<vector<pair<int,int>>>adjlist(V);
        for(int i=0; i<E; i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adjlist[u].push_back({v,wt});
        }
        stack<int>st;
        vector<int>visited(V,0);
        vector<int>distance(V,1e9);
        
        distance[0]=0;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(i,visited,adjlist,st);
            }
        }
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
            for(auto it:adjlist[node]){
                int u=it.first;
                int wt=it.second;
                distance[u]=min(distance[u],wt+distance[node]); 
            }
        }
        for(int i=0; i<V; i++){
            if(distance[i]==1e9)
                distance[i]=-1;
        }
        
        return distance;
        
    }
};
