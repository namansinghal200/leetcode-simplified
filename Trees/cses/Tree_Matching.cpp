#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int par, vector<vector<int>> &adj, vector<vector<int>> &dp)
{
    for (auto i : adj[node])
    {
        if (i != par)
        {
            dfs(i, node, adj, dp);
            dp[node][0] += max(dp[i][0], dp[i][1]);
        }
    }
    for (auto i : adj[node])
    {
        if (i != par)
        {
            dp[node][1] = max(dp[node][1], dp[i][0] + 1 + dp[node][0] - max(dp[i][0], dp[i][1]));
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<vector<int>> dp(n, vector<int>(2));
    dfs(0, -1, adj, dp);
    cout << max(dp[0][0], dp[0][1]) << endl;
}