class Solution
{
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> adjlist(n);
        for (auto it : roads)
        {
            adjlist[it[0]].push_back({it[1], it[2]});
            adjlist[it[1]].push_back({it[0], it[2]});
        }
        vector<long long> time(n, 1e18);
        vector<long long> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>>
            minheap;
        time[0] = 0;
        ways[0] = 1;
        minheap.push({0, 0});

        while (!minheap.empty())
        {
            auto [d, node] = minheap.top();
            minheap.pop();
            for (auto [adjnode, edjtime] : adjlist[node])
            {
                long long ntime = d + edjtime;
                if (ntime < time[adjnode])
                {
                    time[adjnode] = ntime;
                    ways[adjnode] = ways[node];
                    minheap.push({ntime, adjnode});
                }
                else if (ntime == time[adjnode])
                {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};