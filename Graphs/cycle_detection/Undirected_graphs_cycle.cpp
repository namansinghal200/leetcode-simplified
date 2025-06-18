// Problem Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int parent, int node, int V, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        for (auto i : adj[node])
        {
            if (!vis[i])
            {
                if (dfs(node, i, V, adj, vis))
                    return true;
            }
            else if (i != parent)
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        vector<int> adj[V];
        for (auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> par(V);

        for (int i = 0; i < V; i++)
        {
            if (!par[i])
            {
                if (dfs(-1, i, V, adj, par))
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
        cout << (sol.isCycle(V, edges) ? 1 : 0) << endl;
    }
}