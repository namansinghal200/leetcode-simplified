#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> vis;
    vector<int> pathVis;
    vector<int> par;
    vector<vector<int>> adj;
    int sv = -1, ev = -1;

    bool dfs(int node)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        for (auto i : adj[node])
        {

            if (!vis[i])
            {
                par[i] = node;
                if (dfs(i))
                    return true;
            }
            else if (pathVis[i])
            {
                sv = node;
                ev = i;
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }

public:
    void solve()
    {
        int n, m;
        cin >> n >> m;
        vis.resize(n + 1);
        pathVis.resize(n + 1);
        par.resize(n + 1);
        adj.resize(n + 1);

        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }

        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                if (dfs(i))
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
            p = par[p];
        }
        ans.push_back(ev);
        ans.push_back(sv);
        reverse(ans.begin(), ans.end());
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