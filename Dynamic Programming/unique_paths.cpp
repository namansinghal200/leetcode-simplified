// Problem Link: https://leetcode.com/problems/unique-paths/
// Problem Link: https://leetcode.com/problems/unique-paths-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> prev(n, 1), curr(n, 1);

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                curr[j] = prev[j] + curr[j - 1];
            }
            prev = curr;
        }
        return prev[n - 1];
    }
    int uniquePathsWithObstacles(vector<vector<int>> &ob)
    {
        int m = ob.size(), n = ob[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            if (ob[i][0])
                break;
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++)
        {
            if (ob[0][j])
                break;
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (ob[i][j])
                    continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
    int m, n;
    cin >> m >> n;

    Solution sol;
    cout << sol.uniquePaths(m, n) << endl;
}