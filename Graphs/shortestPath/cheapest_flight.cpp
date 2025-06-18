// Problem Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto i : flights)
        {
            adj[i[0]].push_back({i[1], i[2]});
        }
        vector<int> cost(n, 1e9);
        cost[src] = 0;

        queue<vector<int>> pq;
        pq.push({0, 0, src});

        while (!pq.empty())
        {
            int stops = pq.front()[1];
            int costs = pq.front()[0];
            int node = pq.front()[2];
            pq.pop();

            if (stops > k)
                continue;
            for (auto i : adj[node])
            {
                if (costs + i.second < cost[i.first])
                {
                    cost[i.first] = costs + i.second;
                    pq.push({cost[i.first], stops + 1, i.first});
                }
            }
        }
        return (cost[dst] == 1e9) ? -1 : cost[dst];
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
        vector<vector<int>> edges(m, vector<int>(3));
        for (int i = 0; i < m; i++)
        {

            for (int j = 0; j < 3; j++)
            {
                cin >> edges[i][j];
            }
        }
        int src, dst, k;
        cin >> src >> dst >> k;

        Solution sol;
        cout << sol.findCheapestPrice(V, edges, src, dst, k) << endl;
    }
}