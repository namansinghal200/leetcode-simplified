// Problem Link: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // Code here
        vector<vector<pair<int, int>>> adj(V);
        for (auto i : edges)
        {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        vector<int> dist(V, 1e9);
        dist[src] = 0;

        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto i : adj[node])
            {
                if (dist[i.first] > dist[node] + i.second)
                {
                    dist[i.first] = dist[node] + i.second;
                    pq.push({dist[i.first], i.first});
                }
            }
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
        int V, m, src;
        cin >> V >> m >> src;
        vector<vector<int>> edges(m, vector<int>(3));
        for (int i = 0; i < m; i++)
        {

            for (int j = 0; j < 3; j++)
            {
                cin >> edges[i][j];
            }
        }

        Solution sol;
        vector<int> dist = sol.dijkstra(V, edges, src);
        for (auto i : dist)
            cout << i << " ";
        cout << endl;
    }
}