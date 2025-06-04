#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>> &adj, int src)
    {
        // code here
        queue<int> pq;
        int N = adj.size();
        vector<int> dist(N, 1e9);

        dist[src] = 0;
        pq.push(src);
        while (!pq.empty())
        {
            int node = pq.front();
            pq.pop();
            for (auto i : adj[node])
            {
                if (dist[node] + 1 < dist[i])
                {
                    dist[i] = dist[node] + 1;
                    pq.push(i);
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (dist[i] == 1e9)
                dist[i] = -1;
        }
        return dist;
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
        int src;
        cin >> src;
        Solution sol;
        vector<int> ans = sol.shortestPath(adj, src);
        for (auto i : ans)
            cout << i << " ";
        cout << endl;
    }
}