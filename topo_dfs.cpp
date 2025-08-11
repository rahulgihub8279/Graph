#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, unordered_map<int, vector<int>> &adjlist, vector<int> &visited, stack<int> &st)
    {
        visited[node] = 1;
        for (int adjnode : adjlist[node])
        {
            if (!visited[adjnode])
            {
                dfs(adjnode, adjlist, visited, st);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        vector<int> ans;
        vector<int> visited(V, 0);
        stack<int> st;
        unordered_map<int, vector<int>> adjlist;

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adjlist[u].push_back(v);
        }
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adjlist, visited, st);
            }
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};