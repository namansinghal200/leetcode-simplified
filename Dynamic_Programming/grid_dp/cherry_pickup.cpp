// Problem Link: https://leetcode.com/problems/cherry-pickup-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int r, int i, int j, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        int n = grid.size(), m = grid[0].size();
        if (r >= n || i < 0 || j < 0 || i >= m || j >= m)
            return INT_MIN;
        if (r == n - 1)
        {
            if (i == j)
                return grid[r][i];
            return grid[r][i] + grid[r][j];
        }
        if (dp[r][i][j] != -1)
            return dp[r][i][j];
        int ans = INT_MIN;
        for (int di = -1; di <= 1; di++)
        {
            for (int dj = -1; dj <= 1; dj++)
            {
                int num;
                if (i == j)
                {
                    num = grid[r][i] + solve(r + 1, i + di, j + dj, grid, dp);
                }
                else
                {
                    num = grid[r][i] + grid[r][j] + solve(r + 1, i + di, j + dj, grid, dp);
                }
                ans = max(num, ans);
            }
        }
        return dp[r][i][j] = ans;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return solve(0, 0, m - 1, grid, dp);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    Solution sol;
    cout << sol.cherryPickup(mat) << endl;
}