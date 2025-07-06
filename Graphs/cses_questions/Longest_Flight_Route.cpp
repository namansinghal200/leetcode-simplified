#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> in_deg(n + 1, 0);

    // Read edges
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in_deg[b]++;
    }

    // Kahn's algorithm for topological sort
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (in_deg[i] == 0)
            q.push(i);

    vector<int> topo;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int v : adj[u])
        {
            if (--in_deg[v] == 0)
                q.push(v);
        }
    }

    vector<int> dp(n + 1, -1);
    vector<int> par(n + 1, -1);
    dp[1] = 1; // Start from Syrjälä

    for (int u : topo)
    {
        if (dp[u] == -1)
            continue; // skip unreachable
        for (int v : adj[u])
        {
            if (dp[u] + 1 > dp[v])
            {
                dp[v] = dp[u] + 1;
                par[v] = u;
            }
        }
    }

    if (dp[n] == -1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // Reconstruct path
    vector<int> path;
    for (int v = n; v != -1; v = par[v])
        path.push_back(v);
    reverse(path.begin(), path.end());

    cout << path.size() << '\n';
    for (int v : path)
        cout << v << ' ';
    cout << '\n';

    return 0;
}
