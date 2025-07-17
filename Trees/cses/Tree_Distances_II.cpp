#include <bits/stdc++.h>
using namespace std;
#define int long long int

vector<pair<int, int>> ans;
vector<vector<int>> adj;

pair<int, int> dfs1(int node, int par)
{
    if (adj[node].size() == 1 && adj[node][0] == par)
        return ans[node] = {0, 1};
    for (auto i : adj[node])
    {
        if (i != par)
        {
            dfs1(i, node);
            ans[node].first += ans[i].first + ans[i].second;
            ans[node].second += ans[i].second;
        }
    }
    return ans[node];
}

pair<int, int> dfs2(int node, int par)
{
    for (auto i : adj[node])
    {
        if (i != par)
        {
            auto vec = ans[node];
            vec.first -= ans[i].first + ans[i].second;
            vec.second -= ans[i].second;
            ans[i].first += vec.first + vec.second;
            ans[i].second += vec.second;
            dfs2(i, node);
        }
    }
    return ans[node];
}
void solve()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ans.resize(n + 1, {0, 1});

    dfs1(1, -1);
    // for (auto i : ans)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }
    dfs2(1, -1);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i].first << " ";
    }
}

#undef int
int main()
{
    solve();
}