#include <bits/stdc++.h>
#define ll long long
#define s 5005
using namespace std;

ll dp[s][s][2], v[s];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++)
        cin >> v[i];

    memset(dp, -1, sizeof(dp));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                if (k == 0)
                {
                    if (i == j)
                        dp[i][j][k] = 0;
                    else
                        dp[i][j][k] = min(dp[i + 1][j][1], dp[i][j - 1][1]);
                }
                else
                {
                    if (i == j)
                        dp[i][j][k] = v[i];

                    else
                        dp[i][j][k] = max(v[i] + dp[i + 1][j][0], v[j] + dp[i][j - 1][0]);
                }
            }
        }
    }
    cout << dp[0][n - 1][1] << endl;

    return 0;
}
