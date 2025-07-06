#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> vis;
    vector<int> indeg;
    vector<vector<int>> adj;
    vector<int> topo;
    int sv = -1, ev = -1;

    void dfs(int node)
    {
        topo.push_back(node);
        vis[node] = 1;
        for (auto i : adj[node])
        {
            indeg[i]--;
            if (indeg[i] == 0 && !vis[i])
                dfs(i);
        }
    }

public:
    void solve()
    {
        int n, m;
        cin >> n >> m;
        vis.resize(n + 1);
        indeg.resize(n + 1);
        adj.resize(n + 1);

        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            indeg[y]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (!vis[i] && indeg[i] == 0)
            {

                dfs(i);
            }
        }
        if (topo.size() != n)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        for (auto i : topo)
            cout << i << " ";
    }
};
int main()
{
    Solution sol;
    sol.solve();
}