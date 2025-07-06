#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> vis;
    vector<vector<int>> adj;
    int sv = -1, ev = -1;

    bool dfs(int node, int par)
    {
        for (auto i : adj[node])
        {

            if (!vis[i])
            {
                vis[i] = node;
                if (dfs(i, node))
                    return true;
            }
            else if (i != par)
            {
                sv = node;
                ev = i;
                return true;
            }
        }
        return false;
    }

public:
    void solve()
    {
        int n, m;
        cin >> n >> m;
        vis.resize(n + 1);
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
            if (vis[i] == 0)
            {
                vis[i] = -1;
                if (dfs(i, -1))
                    break;
            }
        }
        if (sv == -1)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        int p = sv;
        vector<int> ans;
        // cout << sv << " " << ev << endl;
        while (p != ev)
        {
            ans.push_back(p);
            p = vis[p];
        }
        ans.push_back(ev);
        ans.push_back(sv);
        cout << ans.size() << endl;
        for (auto i : ans)
            cout << i << " ";

        return;
    }
};
int main()
{
    Solution sol;
    sol.solve();
}