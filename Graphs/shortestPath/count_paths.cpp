#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        int mod = 1e9 + 7;
        vector<vector<pair<long long int, long long int>>> adj(n);
        for (auto i : roads)
        {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }

        vector<pair<long long int, long long int>> dist(n, {LLONG_MAX, 0});
        dist[0] = {0, 1};

        priority_queue<vector<long long int>, vector<vector<long long int>>, greater<vector<long long int>>> pq;
        pq.push({0, 0});

        while (!pq.empty())
        {
            long long int dis = pq.top()[0];
            long long int node = pq.top()[1];
            pq.pop();

            for (auto i : adj[node])
            {
                if (dis + i.second == dist[i.first].first)
                {
                    dist[i.first].second = (dist[i.first].second + dist[node].second) % mod;
                }
                else if (dis + i.second < dist[i.first].first)
                {
                    dist[i.first].first = dis + i.second;
                    dist[i.first].second = dist[node].second % mod;
                    pq.push({dist[i.first].first, i.first});
                }
            }
        }
        return dist[n - 1].second;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, m;
        cin >> V >> m;
        vector<vector<int>> edges(m, vector<int>(3));
        for (int i = 0; i < m; i++)
        {

            for (int j = 0; j < 3; j++)
            {
                cin >> edges[i][j];
            }
        }
        int src, dst, k;
        cin >> src >> dst >> k;

        Solution sol;
        cout << sol.countPaths(V, edges) << endl;
    }
}