#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(int i, int j, string &s1, string &s2, set<string> &st, set<pair<pair<int, int>, string>> &mp, vector<vector<int>> &dp, string s)
    {
        if (i == 0 || j == 0)
        {
            reverse(s.begin(), s.end());
            st.insert(s);
            return;
        }

        if (mp.find({{i, j}, s}) != mp.end())
            return;
        mp.insert({{i, j}, s});

        if (s1[i - 1] == s2[j - 1])
        {
            solve(i - 1, j - 1, s1, s2, st, mp, dp, s + s1[i - 1]);
        }
        else
        {
            if (dp[i][j] == dp[i - 1][j])
                solve(i - 1, j, s1, s2, st, mp, dp, s);
            if (dp[i][j] == dp[i][j - 1])
                solve(i, j - 1, s1, s2, st, mp, dp, s);
        }
    }
    vector<string> allLCS(string &s1, string &s2)
    {
        // Code here
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        set<string> st;
        set<pair<pair<int, int>, string>> mp;
        solve(n, m, s1, s2, st, mp, dp, "");

        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    Solution sol;
    vector<string> ans = sol.allLCS(s1, s2);
    for (auto i : ans)
        cout << i << endl;
}