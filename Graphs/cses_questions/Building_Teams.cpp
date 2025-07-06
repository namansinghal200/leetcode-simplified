#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> vis, team;
    vector<vector<int>> adj;
    bool possible = true;
    void dfs(int node, int par)
    {
        for (auto i : adj[node])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                team[i] = !team[node];
                dfs(i, node);
            }
            else if (i != par)
            {
                if (team[i] == team[node])
                {
                    possible = false;
                }
            }
        }
    }

public:
    void solve()
    {
        int n, m;
        cin >> n >> m;
        vis.resize(n + 1);
        team.resize(n + 1);
        adj.resize(n + 1);

        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                dfs(i, 0);
            }
        }

        if (!possible)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            if (team[i])
                cout << 1 << " ";
            else
                cout << 2 << " ";
        }
    }
};
int main()
{
    Solution sol;
    sol.solve();
}