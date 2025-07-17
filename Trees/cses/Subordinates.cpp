#include <bits/stdc++.h>
using namespace std;
#define int long long int

int solve(int node, vector<vector<int>> &adj, vector<int> &subs)
{
    if (adj[node].size() == 0)
        return 0;
    int num = 0;
    for (auto i : adj[node])
    {
        num += 1 + solve(i, adj, subs);
    }
    return subs[node] = num;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    // for (int i = 1; i < adj.size(); i++)
    // {
    //     cout << i << ": ";
    //     for (auto j : adj[i])
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    vector<int> subs(n + 1);
    solve(1, adj, subs);
    for (int i = 1; i < subs.size(); i++)
        cout << subs[i] << " ";
}
#undef int
int main()
{
    solve();
}