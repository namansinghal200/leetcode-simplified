// Problem Link: https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

#include <bits/stdc++.h>
using namespace std;
#define int long long int

class Solution
{
private:
    vector<int> dr = {-1, 0, 1, 0}, dc = {0, -1, 0, 1};
    void dfs(int str, int strc, int r, int c, vector<pair<int, int>> &v, vector<vector<int>> &vis, vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vis[r][c] = 1;
        v.push_back({r - str, c - strc});

        for (int i = 0; i < 4; i++)
        {
            int newr = r + dr[i], newc = c + dc[i];
            if (newr >= 0 && newr < n && newc >= 0 && newc < m && !vis[newr][newc] && grid[newr][newc])
            {
                dfs(str, strc, newr, newc, v, vis, grid);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m));

        set<vector<pair<int, int>>> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j])
                {
                    vector<pair<int, int>> v;
                    dfs(i, j, i, j, v, vis, grid);
                    ans.insert(v);
                }
            }
        }
        return ans.size();
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
    cout << sol.countDistinctIslands(v) << endl;
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