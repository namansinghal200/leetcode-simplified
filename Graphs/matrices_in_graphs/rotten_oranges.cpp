#include <bits/stdc++.h>
using namespace std;
#define int long long int

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        queue<vector<int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({0, i, j});
                    vis[i][j] = 1;
                }
                else if (grid[i][j])
                    count++;
            }
        }

        int ans = 0;
        vector<int> dr = {0, -1, 0, 1}, dc = {-1, 0, 1, 0};
        while (!q.empty())
        {
            auto v = q.front();
            q.pop();

            ans = max(v[0], ans);

            for (int i = 0; i < 4; i++)
            {
                int newr = v[1] + dr[i], newc = v[2] + dc[i];
                if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && !vis[newr][newc])
                {
                    count--;
                    vis[newr][newc] = 1;
                    q.push({v[0] + 1, newr, newc});
                }
            }
        }

        return (count > 0) ? -1 : ans;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    Solution sol;
    cout << sol.orangesRotting(v) << endl;
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