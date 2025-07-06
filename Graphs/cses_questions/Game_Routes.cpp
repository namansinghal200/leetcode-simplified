#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int

void solve()
{
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

    vector<int> dp(n + 1, 0);
    dp[1] = 1; // Start from Syrjälä

    for (int u : topo)
    {
        for (auto i : adj[u])
        {
            dp[i] = (dp[u] + dp[i]) % mod;
        }
    }

    cout << dp[n] << endl;

    return;
}
#undef int
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
