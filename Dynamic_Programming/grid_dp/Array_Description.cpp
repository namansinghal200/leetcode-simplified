#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;

    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    int mod = 1e9 + 7;

    if (v[0] != 0)
        dp[0][v[0]] = 1;
    else
    {
        for (int i = 0; i <= m; i++)
        {
            dp[0][i] = 1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (v[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                if (j - 1 > 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                if (j + 1 <= m)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
            }
        }
        else
        {
            dp[i][v[i]] = (dp[i][v[i]] + dp[i - 1][v[i]]) % mod;
            if (v[i] > 1)
                dp[i][v[i]] = (dp[i][v[i]] + dp[i - 1][v[i] - 1]) % mod;
            if (v[i] < m)
                dp[i][v[i]] = (dp[i][v[i]] + dp[i - 1][v[i] + 1]) % mod;
        }
    }
    int ans = 0;

    for (int i = 1; i <= m; i++)
        ans = (ans + dp[n - 1][i]) % mod;
    cout << ans << endl;
}

#undef int
int main()
{
    solve();
}