#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int node, int N, vector<int> adj[], vector<int> &vis, vector<int> &pathVis)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        for (auto i : adj[node])
        {
            if (!vis[i])
            {
                if (dfs(i, N, adj, vis, pathVis))
                    return true;
            }
            else if (pathVis[i])
                return true;
        }
        pathVis[node] = 0;
        return false;
    }
    bool isCyclic(int N, vector<vector<int>> &edges)
    {
        vector<int> adj[N];
        vector<int> vis(N), pathVis(N);

        for (auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
        }
        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, N, adj, vis, pathVis))
                    return true;
            }
        }
        return false;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, m;
        cin >> V >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            edges.push_back({x, y});
        }
        Solution sol;
        cout << (sol.isCyclic(V, edges) ? 1 : 0) << endl;
    }
}