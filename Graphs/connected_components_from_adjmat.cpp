// Problem Link: https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;
#define int long long int
class Solution
{
private:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj)
    {
        vis[node] = 1;
        for (auto i : adj[node])
        {
            if (!vis[i])
            {
                dfs(i, vis, adj);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &mat)
    {
        int n = mat.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j])
                    adj[i].push_back(j);
            }
        }
        int ans = 0;
        vector<int> vis(n);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj);
                ans++;
            }
        }
        return ans;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    Solution sol;
    cout << sol.findCircleNum(v) << endl;
}

#undef int
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}