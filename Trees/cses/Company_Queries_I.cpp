#include <bits/stdc++.h>
using namespace std;
#define int long long int

vector<vector<int>> ansc;
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
        preprocess(i, node, adj);
    }
}
int get(int node, int k)
{
    if (k == 0)
        return node;
    if (node == -1)
        return -1;
    for (int i = 20; i >= 0; i--)
    {
        if (k & (1 << i))
        {
            return get(ansc[node][i], k - (1 << i));
        }
    }
    return -1;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    ansc.resize(n + 1, vector<int>(21, -1));

    preprocess(1, -1, adj);

    for (int i = 0; i < q; i++)
    {
        int x, k;
        cin >> x >> k;
        cout << get(x, k) << endl;
    }
}

#undef int
int main()
{
    solve();
}