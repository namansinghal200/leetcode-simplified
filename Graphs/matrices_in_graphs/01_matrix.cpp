// Problem Link: https://leetcode.com/problems/01-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));

        queue<vector<int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({0, i, j});
                }
            }
        }

        vector<int> dr = {-1, 0, 1, 0}, dc = {0, -1, 0, 1};
        while (!q.empty())
        {
            int d = q.front()[0], r = q.front()[1], c = q.front()[2];
            q.pop();

            if (dist[r][c] != -1)
                continue;
            dist[r][c] = d;

            for (int i = 0; i < 4; i++)
            {
                int newr = r + dr[i], newc = c + dc[i];
                if (newr >= 0 && newr < n && newc >= 0 && newc < m && dist[newr][newc] == -1)
                {
                    q.push({d + 1, newr, newc});
                }
            }
        }
        return dist;
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
    vector<vector<int>> ans = sol.updateMatrix(v);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}