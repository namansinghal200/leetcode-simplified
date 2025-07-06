#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<long long int> dp(amount + 1, 1e9);
        dp[0] = 0;
        for (long long int i = 0; i <= amount; i++)
        {
            for (auto j : coins)
            {
                if (i + j <= amount)
                    dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
        return (dp[amount] >= 1e9 ? -1 : dp[amount]);
    }

    // get count
    int change(int amount, vector<int> &coins)
    {
        vector<long long int> dp(amount + 1);
        long long int mod = INT_MAX;
        dp[0] = 1;
        for (auto j : coins)
        {
            for (int i = j; i <= amount; i++)
            {
                dp[i] = (dp[i] + dp[i - j]) % mod;
            }
        }
        return dp[amount];
    }
};
int main()
{
    int n, sum;
    cin >> n >> sum;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    Solution sol;
    cout << sol.coinChange(v, sum) << endl;
}