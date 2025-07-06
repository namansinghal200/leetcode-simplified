#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    void solve()
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<int> vis(n + 1);
        vector<int> dist(n + 1);
        queue<int> q;
        q.push(1);
        vis[1] = 1;

        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (auto i : adj[x])
            {
                if (!vis[i])
                {
                    dist[i] = dist[x] + 1;
                    vis[i] = x;
                    q.push(i);
                }
            }
        }

        if (!vis[n])
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        // cout << "possible" << endl;
        cout << dist[n] + 1 << endl;
        vector<int> ans(dist[n] + 1, 1);
        int start = n, i = dist[n];
        while (start != 1)
        {
            ans[i] = start;
            i--;
            start = vis[start];
        }
        for (auto i : ans)
            cout << i << " ";
    }
};
int main()
{
    Solution sol;
    sol.solve();
}