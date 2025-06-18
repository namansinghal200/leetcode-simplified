// Problem Link: https://leetcode.com/problems/surrounded-regions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int n = board.size(), m = board[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && board[i][j] == 'O')
                {
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>> vis(n, vector<int>(m));
        vector<int> dr = {-1, 0, 1, 0}, dc = {0, -1, 0, 1};
        while (!q.empty())
        {
            int r = q.front().first, c = q.front().second;
            q.pop();

            if (vis[r][c])
                continue;
            vis[r][c] = 1;

            for (int i = 0; i < 4; i++)
            {
                int newr = r + dr[i], newc = c + dc[i];
                if (newr >= 0 && newr < n && newc >= 0 && newc < m && !vis[newr][newc] && board[newr][newc] == 'O')
                {
                    q.push({newr, newc});
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};

void soll()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    Solution sol;
    sol.solve(v);
    for (auto i : v)
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
        soll();
    }
}