class Solution {
  public: 
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int>indegree(V,0);
        unordered_map<int,vector<int>>adjlist;
        queue<int>q;
        int cnt=0;
        
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adjlist[u].push_back(v);
        }
        for(auto it:adjlist){
            for(int u:it.second)
                indegree[u]++;
        }
        for(int i=0; i<V; i++){
            if(indegree[i]==0) 
                q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto it:adjlist[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return cnt!=V;
    }
};