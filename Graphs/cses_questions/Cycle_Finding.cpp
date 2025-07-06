#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges.push_back({x, y, z});
    }
    vector<int> par(n + 1, 0);
    vector<int> dist(n + 1);
    int pnt = -1;

    for (int i = 0; i < n; i++)
    {
        pnt = -1;
        for (auto j : edges)
        {
            if (dist[j[1]] > dist[j[0]] + j[2])
            {
                dist[j[1]] = dist[j[0]] + j[2];
                par[j[1]] = j[0];
                pnt = j[1];
            }
        }
    }

    if (pnt == -1)
    {
        cout << "NO" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
        pnt = par[pnt];

    vector<int> cycle;
    int cur = pnt;
    do
    {
        cycle.push_back(cur);
        cur = par[cur];
    } while (cur != pnt);
    cycle.push_back(pnt);
    reverse(cycle.begin(), cycle.end());

    cout << "YES" << endl;
    for (int x : cycle)
        cout << x << " ";
    cout << endl;
}

#undef int
int main()
{
    solve();
}