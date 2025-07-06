#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> comes_from(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        comes_from[--y].push_back(--x);
    }

    // for (auto i : comes_from)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    vector<vector<int>> dp((1 << n), vector<int>(n, 0));
    dp[1][0] = 1;
    int mod = 1e9 + 7;

    for (int i = 2; i < (1 << n); i++)
    {
        if (i & (1 << 0) == 0)
            continue;
        if (i & (1 << (n - 1)) && i != ((1 << n) - 1))
            continue;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                int prev = i ^ (1 << j);
                for (auto k : comes_from[j])
                {
                    if (i & (1 << k))
                    {
                        dp[i][j] = (dp[i][j] + dp[prev][k]) % mod;
                    }
                }
            }
        }
    }
    // for (auto i : dp)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[(1 << n) - 1][n - 1] << endl;
}
#undef int
int main()
{
    solve();
}