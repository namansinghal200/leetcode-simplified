#include <bits/stdc++.h>
using namespace std;
#define int long long int

vector<vector<int>> ansc;
vector<int> depth;
vector<int> pc;
void preprocess(int node, int par, vector<vector<int>> &adj)
{
    ansc[node][0] = par;
    for (int i = 1; i <= 20; i++)
    {
        if (ansc[node][i - 1] != -1)
        {
            ansc[node][i] = ansc[ansc[node][i - 1]][i - 1];
        }
    }
    for (auto i : adj[node])
    {
        if (i != par)
        {
            depth[i] = depth[node] + 1;
            preprocess(i, node, adj);
        }
    }
}
int get(int a, int b)
{
    int n1 = a, n2 = b;
    if (depth[a] < depth[b])
        swap(a, b);
    for (int i = 20; i >= 0; i--)
    {
        if (depth[a] - (1 << i) >= depth[b])
        {
            a = ansc[a][i];
        }
    }
    if (a == b)
        return a;
    for (int i = 20; i >= 0; i--)
    {
        if (ansc[a][i] != ansc[b][i])
        {
            a = ansc[a][i];
            b = ansc[b][i];
        }
    }
    int lca = ansc[a][0];
    return lca;
}
void dfssum(int node, int par, vector<vector<int>> &adj)
{
    for (auto i : adj[node])
    {
        if (i != par)
        {
            dfssum(i, node, adj);
            pc[node] += pc[i];
        }
    }
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ansc.resize(n + 1, vector<int>(21, -1));
    depth.resize(n + 1);
    pc.resize(n + 1);

    preprocess(1, -1, adj);

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        int lca = get(a, b);
        pc[a]++;
        pc[b]++;
        pc[lca]--;
        if (ansc[lca][0] != -1)
            pc[ansc[lca][0]]--;
    }
    dfssum(1, -1, adj);
    for (int i = 1; i <= n; i++)
        cout << pc[i] << " ";
    cout << endl;
}

#undef int
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}