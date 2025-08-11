class Solution {
  public: 
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int>ans;
        vector<int>indegree(V,0);
        queue<int>q;
        unordered_map<int,vector<int>>adjlist;
        
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adjlist[u].push_back(v);
        }
        for(auto it:adjlist){
            for(int v:it.second)
                indegree[v]++;
        }
        for(int i=0; i<V; i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adjlist[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        return ans;
    }
};