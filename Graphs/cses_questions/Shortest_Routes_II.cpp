#include <bits/stdc++.h>
using namespace std;

#define int long long int
class Solution
{

public:
    void solve()
    {
        int n, m, q;
        cin >> n >> m >> q;

        vector<vector<int>> dist(n + 1, vector<int>(n + 1, LLONG_MAX));

        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            dist[x][y] = min(z, dist[x][y]);
            dist[y][x] = min(z, dist[y][x]);
        }

        for (int i = 1; i <= n; i++)
            dist[i][i] = 0;
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        for (int i = 0; i < q; i++)
        {
            int x, y;
            cin >> x >> y;
            if (dist[x][y] == LLONG_MAX)
                cout << -1 << endl;
            else
                cout << dist[x][y] << endl;
        }

        return;
    }
};

#undef int
int main()
{
    Solution sol;
    sol.solve();
}