// Problem Link: https://leetcode.com/problems/path-with-minimum-effort/description/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &h)
    {
        int n = h.size(), m = h[0].size();
        vector<vector<int>> eff(n, vector<int>(m, 1e9));
        eff[0][0] = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, -1, 0, 1};
        while (!q.empty())
        {
            int r = q.front().first, c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int newr = r + dr[i], newc = c + dc[i];
                if (newr >= 0 && newc >= 0 && newr < n && newc < m && max(eff[r][c], abs(h[newr][newc] - h[r][c])) < eff[newr][newc])
                {
                    eff[newr][newc] = max(eff[r][c], abs(h[newr][newc] - h[r][c]));
                    q.push({newr, newc});
                }
            }
        }
        return eff[n - 1][m - 1];
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
    cout << sol.minimumEffortPath(v) << endl;
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