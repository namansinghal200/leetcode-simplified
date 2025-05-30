#include <bits/stdc++.h>
using namespace std;
#define int long long int

class Solution
{
private:
    vector<int> dr = {-1, 0, 1, 0}, dc = {0, -1, 0, 1};
    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vis[r][c] = 1;
        for (int i = 0; i < 4; i++)
        {
            int newr = r + dr[i], newc = c + dc[i];
            if (newr >= 0 && newr < n && newc >= 0 && newc < m && !vis[newr][newc] && mat[newr][newc])
            {
                dfs(newr, newc, vis, mat);
            }
        }
    }

public:
    int connectedComponents(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] && !vis[i][j])
                {
                    dfs(i, j, vis, mat);
                    ans++;
                }
            }
        }
        return ans;
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
    cout << sol.connectedComponents(v) << endl;
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