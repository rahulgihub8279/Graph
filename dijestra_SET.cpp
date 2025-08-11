// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) { 
        vector<vector<pair<int,int>>>adjlist(V);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adjlist[u].push_back({v,wt});
            adjlist[v].push_back({u,wt});
        }
        vector<int>dist(V,1e9);
        set<pair<int,int>>st;
        dist[src]=0;
        st.insert({0,src});
        while(!st.empty()){
            auto it=*(st.begin());
            st.erase(it);
            
            int node=it.second;
            int d=it.first; 
            for(auto it:adjlist[node]){
                int adjnode=it.first;
                int wt=it.second;
                if(d+wt<dist[adjnode]){
                    if(dist[adjnode]!=1e9)
                        st.erase({dist[adjnode],adjnode});
                    dist[adjnode]=d+wt;
                    st.insert({d+wt,adjnode});
                }
            }
        }
        
        return dist;
    }
};