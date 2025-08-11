class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        vector<vector<pair<int, int>>> adjlist(V);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        vector<int> dist(V, 1e9);

        dist[src] = 0;
        minheap.push({0, src});
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adjlist[u].push_back({v, wt});
            adjlist[v].push_back({u, wt});
        }

        while (!minheap.empty())
        {
            int d = minheap.top().first;
            int node = minheap.top().second;
            minheap.pop();
            for (auto it : adjlist[node])
            {
                int adjnode = it.first;
                int wt = it.second;
                if (d + wt < dist[adjnode])
                {
                    dist[adjnode] = d + wt;
                    minheap.push({d + wt, adjnode});
                }
            }
        }

        return dist;
    }
};