class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        int mod = 100000;
        vector<int> dist(mod, 1e9);
        queue<pair<int, int>> q;
        
        q.push({start, 0});
        dist[start] = 0;
        if (start == end)
            return 0;

        while (!q.empty())
        {
            int node = q.front().first;
            int step = q.front().second;
            q.pop();

            for (auto it : arr)
            {
                int num = (node * it) % mod;
                if (num == end)
                    return step + 1;
                if (step + 1 < dist[num])
                {
                    dist[num] = step + 1;
                    q.push({num, step + 1});
                }
            }
        }

        return -1;
    }
};
