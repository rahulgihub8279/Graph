class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adjlist(n);
        for (auto it : flights)
        {
            int u = it[0];
            int v = it[1];
            int cost = it[2];
            adjlist[u].push_back({v, cost});
        }
        vector<int> dist(n, 1e9);
        queue<pair<int, pair<int, int>>> q;
        //* {stop,{node,dist}}
        
        dist[src] = 0;
        q.push({0, {src, 0}});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stop = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if (stop > k) continue;
            
            for (auto it : adjlist[node])
            {
                int adjnode = it.first;
                int edgeWeight = it.second;
                if (cost + edgeWeight < dist[adjnode])
                {
                    dist[adjnode] = cost + edgeWeight;
                    q.push({stop + 1, {adjnode, cost + edgeWeight}});
                }
            }
        }
        if (dist[dst] == 1e9)
            return -1;

        return dist[dst];
    }
};