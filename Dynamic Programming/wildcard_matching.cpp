#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
            return 1;
        if (i == 0)
        {
            for (int k = 1; k <= j; k++)
            {
                if (p[k - 1] != '*')
                    return 0;
            }
            return 1;
        }
        if (j == 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        if (p[j - 1] == '*')
            return dp[i][j] = solve(i - 1, j, s, p, dp) || solve(i, j - 1, s, p, dp);
        else
            return dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && solve(i - 1, j - 1, s, p, dp);
    }
    bool isMatch(string s, string p)
    {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(n, m, s, p, dp);
    }
};
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    Solution sol;
    cout << sol.isMatch(s1, s2) << endl;
}