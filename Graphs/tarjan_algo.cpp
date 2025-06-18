// Problem Link: https://leetcode.com/problems/critical-connections-in-a-network/discuss/382385/find-bridges-in-a-graph

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int timer = 1;
    void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &tin, vector<int> &low, vector<int> &vis, vector<vector<int>> &bridges)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        for (auto i : adj[node])
        {
            if (i == parent)
                continue;
            if (vis[i])
            {
                low[node] = min(low[node], low[i]);
            }
            else
            {
                dfs(i, node, adj, tin, low, vis, bridges);
                low[node] = min(low[i], low[node]);
                if (low[i] > tin[node])
                {
                    bridges.push_back({i, node});
                }
            }
        }
    }
    vector<vector<int>> tarjan(int n, vector<vector<int>> &adj)
    {
        vector<int> tin(n), low(n), vis(n);
        vector<vector<int>> bridges;
        dfs(0, -1, adj, tin, low, vis, bridges);
        return bridges;
    }
};

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    for (auto &i : edges)
    {
        cin >> i[0] >> i[1];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    Solution obj;
    vector<vector<int>> ans = obj.tarjan(n, adj);
    for (auto i : ans)
    {
        cout << i[0] << " " << i[1] << endl;
    }
    return 0;
}