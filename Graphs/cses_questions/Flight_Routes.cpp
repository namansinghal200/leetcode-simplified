#include <bits/stdc++.h>
using namespace std;

#define int long long int
class Solution
{

public:
    void solve()
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<pair<int, int>>> adj(n + 1);

        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            adj[x].push_back({y, z});
        }

        vector<int> dist(n + 1, LLONG_MAX);
        vector<int> cnt(n + 1);
        dist[1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, 1});
        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            cnt[node]++;
            if (node == n)
            {
                cout << dis << " ";
                if (cnt[node] == k)
                {

                    return;
                }
            }

            if (cnt[node] <= k)
            {

                for (auto i : adj[node])
                {
                    pq.push({i.second + dis, i.first});
                }
            }
        }
    }
};

#undef int
int main()
{
    Solution sol;
    sol.solve();
}