#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> adj;
int farthest_node, max_dist;

void dfs(int node, int parent, int dist)
{
    if (dist > max_dist)
    {
        max_dist = dist;
        farthest_node = node;
    }
    for (auto neighbor : adj[node])
    {
        if (neighbor != parent)
        {
            dfs(neighbor, node, dist + 1);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    adj.assign(n + 1, {});

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    max_dist = -1;
    dfs(1, -1, 0);

    int start = farthest_node;
    max_dist = -1;
    dfs(start, -1, 0);

    cout << max_dist << endl;
}

#undef int
int main()
{
    solve();
}
