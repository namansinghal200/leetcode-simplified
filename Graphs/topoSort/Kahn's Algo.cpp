// we can use Kahn's Algorithm for cycle detection in a directed graph as well. In a DAG, V nodes will enter
// the queue but in a acyclic graph, the number would be less.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // code here
        vector<int> indeg(V);
        vector<vector<int>> adj(V);

        for (auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            indeg[i[1]]++;
        }

        queue<int> q;
        vector<int> vis(V), ans;
        for (int i = 0; i < V; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
                ans.push_back(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto i : adj[node])
            {
                indeg[i]--;
                if (indeg[i] == 0)
                {
                    q.push(i);
                    ans.push_back(i);
                }
            }
        }
        return ans;
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
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            edges.push_back({x, y});
        }
        Solution sol;
        vector<int> ans = sol.topoSort(V, edges);
        for (auto i : ans)
            cout << i << " ";
        cout << endl;
    }
}