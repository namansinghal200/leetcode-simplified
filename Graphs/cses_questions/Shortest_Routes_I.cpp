#include <bits/stdc++.h>
using namespace std;

#define int long long int
class Solution
{

public:
    void solve()
    {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> adj(n + 1);

        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            adj[x].push_back({y, z});
        }

        vector<int> dist(n + 1, LLONG_MAX);
        dist[1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dis > dist[node])
                continue;

            for (auto i : adj[node])
            {
                if (dist[i.first] > dist[node] + i.second)
                {
                    dist[i.first] = dist[node] + i.second;
                    pq.push({dist[i.first], i.first});
                }
            }
        }
        for (int i = 1; i <= n; i++)
            cout << dist[i] << " ";

        return;
    }
};

#undef int
int main()
{
    Solution sol;
    sol.solve();
}