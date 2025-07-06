// Problem Link: https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

// finding the number of strongly connected components
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> ans;
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
    void kosaraju(int V, vector<int> adj[])
    {
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
        cout << scc << endl;
        for (int i = 1; i <= V; i++)
            cout << ans[i] << " ";
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
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    Solution obj;
    obj.kosaraju(n, adj);
    return 0;
}