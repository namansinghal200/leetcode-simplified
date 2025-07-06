#include <bits/stdc++.h>
using namespace std;
#define int long long int

class Solution
{
private:
    vector<int> dr = {-1, 0, 1, 0}, dc = {0, -1, 0, 1};
    void dfs(int i, int j, int n, int m, vector<string> &v, vector<vector<int>> &vis)
    {
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++)
        {
            int newr = dr[k] + i, newc = dc[k] + j;
            if (newr >= 0 && newr < n && newc >= 0 && newc < m && v[newr][newc] == '.' && !vis[newr][newc])
            {
                dfs(newr, newc, n, m, v, vis);
            }
        }
    }

public:
    int solve()
    {
        int n, m;
        cin >> n >> m;
        vector<string> v(n, "");
        for (auto &i : v)
            cin >> i;

        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && v[i][j] == '.')
                {
                    count++;
                    dfs(i, j, n, m, v, vis);
                }
            }
        }
        return count;
    }
};
#undef int
int main()
{
    Solution sol;
    cout << sol.solve() << endl;
}