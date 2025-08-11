class Solution {
public:
    void bfs(vector<vector<int>>& isConnected, vector<int>& visited, int node) {
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        while (!q.empty()) {
            int fnode = q.front();
            q.pop();
            for (int j = 0; j < isConnected.size(); j++) {
                if (isConnected[fnode][j] == 1 && !visited[j]) {
                    q.push(j);
                    visited[j] = 1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        int count = 0;
        vector<int> visited(v, 0);

        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                bfs(isConnected, visited, i);
                count++;
            }
        }

        return count;
    }
};