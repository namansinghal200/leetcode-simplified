#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> wt(n);
    for (auto &i : wt)
        cin >> i;

    vector<pair<int, int>> dp((1 << n), {n + 1, 0});
    dp[0] = {1, 0};

    for (int i = 1; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                pair<int, int> prev = dp[i ^ (1 << j)];
                if (prev.second + wt[j] <= x)
                {
                    prev.second += wt[j];
                }
                else
                {
                    prev.first += 1;
                    prev.second = wt[j];
                }
                dp[i] = min(dp[i], prev);
            }
        }
    }
    // for (int i = 0; i < (1 << n); i++)
    // {
    //     cout << i << ' ' << dp[i].first << " " << dp[i].second << endl;
    // }
    cout << dp[(1 << n) - 1].first << endl;
}

int main()
{
    solve();
}