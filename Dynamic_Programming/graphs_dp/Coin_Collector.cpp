#include <bits/stdc++.h>
using namespace std;
#define int long long int

class Solution
{
private:
    vector<int> ans;
    map<int, int> coins;
    vector<int> v;
    void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj, st);
            }
        }

        st.push(node);
    }

    void dfs3(int cnt, int node, vector<int> &vis, vector<int> adjT[])
    {
        ans[node] = cnt;
        coins[cnt] += v[node];
        vis[node] = 1;
        for (auto it : adjT[node])
        {
            if (!vis[it])
            {
                dfs3(cnt, it, vis, adjT);
            }
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    pair<map<int, int>, vector<int>> kosaraju(int V, vector<int> adj[], vector<int> &vec)
    {
        v = vec;
        ans.resize(V + 1);
        vector<int> vis(V + 1, 0);
        stack<int> st;
        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, st);
            }
        }

        vector<int> adjT[V + 1];
        for (int i = 1; i <= V; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                // i -> it
                // it -> i
                adjT[it].push_back(i);
            }
        }
        int scc = 0;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!vis[node])
            {
                scc++;
                dfs3(scc, node, vis, adjT);
            }
        }
        return {coins, ans};
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    vector<vector<int>> edges(m, vector<int>(2));
    for (auto &i : edges)
    {
        cin >> i[0] >> i[1];
    }

    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    Solution obj;
    auto [coins, scc] = obj.kosaraju(n, adj, v);
    int scc_count = coins.size();

    vector<set<int>> newAdj(scc_count + 1);
    for (auto i : edges)
    {
        if (scc[i[0]] != scc[i[1]])
            newAdj[scc[i[0]]].insert(scc[i[1]]);
    }

    // Topo sort + DP
    vector<int> indeg(scc_count + 1, 0);
    for (int u = 1; u <= scc_count; ++u)
        for (int v : newAdj[u])
            indeg[v]++;

    queue<int> q;
    vector<int> dp(scc_count + 1, 0);

    for (int i = 1; i <= scc_count; ++i)
    {
        dp[i] = coins[i];
        if (indeg[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : newAdj[u])
        {
            if (dp[v] < dp[u] + coins[v])
                dp[v] = dp[u] + coins[v];
            if (--indeg[v] == 0)
                q.push(v);
        }
    }

    int ans = *max_element(dp.begin(), dp.end());
    cout << ans << "\n";
}

#undef int
int main()
{
    solve();
}