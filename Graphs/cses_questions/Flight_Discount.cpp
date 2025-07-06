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

        vector<vector<int>> dist(n + 1, vector<int>(2, LLONG_MAX));
        dist[1][0] = 0;
        dist[1][1] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 1, 1});
        while (!pq.empty())
        {
            int dis = pq.top()[0];
            int node = pq.top()[2];
            int cnt = pq.top()[1];
            pq.pop();

            if (dis > dist[node][!cnt])
                continue;

            for (auto i : adj[node])
            {
                if (cnt)
                {
                    if (dist[i.first][0] > dist[node][0] + i.second)
                    {
                        dist[i.first][0] = dist[node][0] + i.second;
                        pq.push({dist[i.first][0], 1, i.first});
                    }
                    if (dist[i.first][1] > dist[node][0] + (i.second / 2))
                    {
                        dist[i.first][1] = dist[node][0] + (i.second / 2);
                        pq.push({dist[i.first][1], 0, i.first});
                    }
                }
                else
                {
                    if (dist[i.first][1] > dist[node][1] + i.second)
                    {
                        dist[i.first][1] = dist[node][1] + i.second;
                        pq.push({dist[i.first][1], 0, i.first});
                    }
                }
            }
        }
        cout << min(dist[n][0], dist[n][1]) << endl;

        return;
    }
};

#undef int
int main()
{
    Solution sol;
    sol.solve();
}