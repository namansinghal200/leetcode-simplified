#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1])
            return -1;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;

        queue<vector<int>> pq;
        pq.push({1, 0, 0});
        while (!pq.empty())
        {
            int dis = pq.front()[0];
            int r = pq.front()[1];
            int c = pq.front()[2];
            pq.pop();

            if (r == n - 1 && c == n - 1)
                return dis;

            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    int newr = r + i, newc = c + j;
                    if (newr >= 0 && newc >= 0 && newr < n && newc < n && grid[newr][newc] == 0 && dist[newr][newc] > dist[r][c] + 1)
                    {
                        dist[newr][newc] = dist[r][c] + 1;
                        pq.push({dist[newr][newc], newr, newc});
                    }
                }
            }
        }
        return -1;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    Solution sol;
    cout << sol.shortestPathBinaryMatrix(v) << endl;
}

#undef int
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}