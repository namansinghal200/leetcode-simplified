#include <bits/stdc++.h>
using namespace std;

pair<int, vector<vector<int>>> prim(int V, vector<vector<int>> &edges)
{
    vector<vector<vector<int>>> adj(V);
    for (auto i : edges)
    {
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    vector<int> vis(V);
    vis[0] = 1;
    int ans = 0;
    vector<vector<int>> mst;

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        ans += dist;

        for (auto i : adj[node])
        {
            if (!vis[i[0]])
            {
                mst.push_back({node, i[0]});
                pq.push({i[1], i[0]});
                vis[i[0]] = 1;
            }
        }
    }
    return {ans, mst};
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges(m, vector<int>(3));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> edges[i][j];
            }
        }
        // for (auto i : edges)
        // {
        //     cout << i[0] << " " << i[1] << " " << i[2] << endl;
        // }
        auto ans = prim(n, edges);
        cout << ans.first << endl;
        for (auto i : ans.second)
        {
            cout << i[0] << " " << i[1] << endl;
        }
    }
}