#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v1(n), v2(m);
    for (auto &i : v1)
        cin >> i;
    for (auto &i : v2)
        cin >> i;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (v1[i - 1] == v2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
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
    vector<int> ans;
    int stx = n, sty = m;
    while (dp[stx][sty] > 0)
    {
        if (v1[stx - 1] == v2[sty - 1])
        {
            ans.push_back(v1[stx - 1]);
            stx--;
            sty--;
        }
        else if (dp[stx - 1][sty] > dp[stx][sty - 1])
        {
            stx--;
        }
        else
        {
            sty--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << " ";
}
#undef int
int main()
{
    solve();
}