#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int node, int col, vector<int> &color, vector<vector<int>> &graph)
    {
        color[node] = col;
        for (auto i : graph[node])
        {
            if (color[i] == -1)
            {
                if (dfs(i, !col, color, graph) == false)
                    return false;
            }
            else if (color[i] == color[node])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (dfs(i, 0, color, graph) == false)
                    return false;
            }
        }
        return true;
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
        vector<vector<int>> adj(V);
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        Solution sol;
        cout << (sol.isBipartite(adj) ? 1 : 0) << endl;
    }
}