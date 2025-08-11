class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& pathvis,vector<vector<int>>& graph, vector<int>& check) {
        vis[node] = 1;
        pathvis[node] = 1;
        check[node] = 0;

        for (auto it : graph[node]) {
            if (!vis[it]) {
                if (dfs(it, vis, pathvis, graph, check)) {
                    check[it] = 0;
                    return true;
                }
            } else if (pathvis[it]) {
                check[it] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> vis(V, 0),pathvis(V, 0),check(V, 0),ans;

        for (int i = 0; i < V; i++) {
            if (!vis[i])
                dfs(i, vis, pathvis, graph, check);
        }
        for (int i = 0; i < V; i++) {
            if (check[i])
                ans.push_back(i);
        }
        return ans;
    }
};