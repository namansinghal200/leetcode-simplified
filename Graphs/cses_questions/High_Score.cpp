#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

void dfs(int u, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[u] = true;
    for (int v : adj[u])
        if (!vis[v])
            dfs(v, adj, vis);
}

int32_t main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;
    vector<vector<int>> adj(n + 1), revAdj(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int a, b, x;
        cin >> a >> b >> x;
        edges.push_back({a, b, x});
        adj[a].push_back(b);
        revAdj[b].push_back(a); // for reverse DFS
    }

    vector<bool> canReachFromStart(n + 1, false), canReachEnd(n + 1, false);
    dfs(1, adj, canReachFromStart);
    dfs(n, revAdj, canReachEnd);

    vector<int> dist(n + 1, -INF);
    dist[1] = 0;

    for (int i = 1; i <= n - 1; ++i)
    {
        for (auto &e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            if (dist[u] != -INF && dist[v] < dist[u] + w)
                dist[v] = dist[u] + w;
        }
    }

    for (auto &e : edges)
    {
        int u = e[0], v = e[1], w = e[2];
        if (dist[u] != -INF && dist[v] < dist[u] + w)
        {
            if (canReachFromStart[u] && canReachEnd[v])
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << dist[n] << endl;
    return 0;
}
