#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> adj;
vector<int> dist_from_u, dist_from_v;

void dfs(int node, int parent, int dist, vector<int> &dist_arr)
{
    dist_arr[node] = dist;
    for (auto neighbor : adj[node])
    {
        if (neighbor != parent)
        {
            dfs(neighbor, node, dist + 1, dist_arr);
        }
    }
}

pair<int, int> find_farthest(int start, int n)
{
    vector<int> dist(n + 1, -1);
    dfs(start, -1, 0, dist);
    int max_dist = -1, farthest_node = -1;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] > max_dist)
        {
            max_dist = dist[i];
            farthest_node = i;
        }
    }
    return {farthest_node, max_dist};
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

    int u = find_farthest(1, n).first;
    int v = find_farthest(u, n).first;

    dist_from_u.assign(n + 1, 0);
    dist_from_v.assign(n + 1, 0);

    dfs(u, -1, 0, dist_from_u);
    dfs(v, -1, 0, dist_from_v);

    for (int i = 1; i <= n; i++)
    {
        cout << max(dist_from_u[i], dist_from_v[i]) << " ";
    }
    cout << endl;
}

#undef int
int main()
{
    solve();
}
