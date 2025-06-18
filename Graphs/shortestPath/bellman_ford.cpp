// Problem Link: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        // Code here
        vector<int> dist(V, 1e8);
        dist[src] = 0;

        for (int i = 0; i < V - 1; i++)
        {
            for (auto j : edges)
            {
                if (dist[j[0]] != 1e8 && dist[j[1]] > dist[j[0]] + j[2])
                {
                    dist[j[1]] = dist[j[0]] + j[2];
                }
            }
        }

        for (auto j : edges)
        {
            if (dist[j[0]] != 1e8 && dist[j[1]] > dist[j[0]] + j[2])
            {
                return {-1};
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
        vector<int> dist = sol.bellmanFord(V, edges, src);
        for (auto i : dist)
            cout << i << " ";
        cout << endl;
    }
}