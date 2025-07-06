#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> vis;
    vector<vector<int>> adj;
    vector<int> vec, ans;
    int sv = -1, ev = -1;

    bool dfs(int node)
    {
        vec.push_back(node);
        vis[node] = 1;
        for (auto i : adj[node])
        {

            if (!vis[i])
            {
                if (dfs(i))
                    return true;
            }
            else if (i == 1)
            {
                for (auto j : vec)
                    cout << j << " ";
                cout << endl;
                if (vec.size() == vis.size() - 1)
                {
                    ans = vec;
                    return true;
                }
            }
        }
        vec.pop_back();
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

        if (!dfs(1))
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }

        // int p = sv;
        // vector<int> ans;
        // // cout << sv << " " << ev << endl;
        // while (p != ev)
        // {
        //     ans.push_back(p);
        //     p = vis[p];
        // }
        // ans.push_back(ev);
        // ans.push_back(sv);
        // cout << ans.size() << endl;
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