#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool check(int node,unordered_map<int,vector<int>>&adjlist,vector<int>&visited){
        queue<int>q;
        q.push(node);
        visited[node]=0;
        while(!q.empty()){
            int fnode=q.front();
            q.pop();
            for(int adjnode:adjlist[fnode]){
                if(visited[adjnode]==-1){
                    visited[adjnode]=!visited[fnode];
                    q.push(adjnode);
                }
                else if(visited[adjnode]==visited[fnode]){
                    return false;
                }
            }
        }    
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        unordered_map<int,vector<int>>adjlist;
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        vector<int>visited(V,-1);
        for(int i=0; i<V; i++){
            if(visited[i]==-1){
                if(!check(i,adjlist,visited))
                    return false;
            }    
        }
        return true;
    }
};
int main(){


    return 0;
}