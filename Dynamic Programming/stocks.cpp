#include <bits/stdc++.h>
using namespace std;

// in case of cooldown of k days, just change the j==1 (selling condition) to max(prices[i]+solve(i+1+k,...), solve(i+1,..))
// in case of transaction fee, just subtract the fee once either while buying or selling.

class Solution
{
public:
    int solve(int i, int j, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (i == prices.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (j == 1)
        {
            return dp[i][j] = max(prices[i] + solve(i + 1, 0, prices, dp), solve(i + 1, 1, prices, dp));
        }
        return dp[i][j] = max(-prices[i] + solve(i + 1, 1, prices, dp), solve(i + 1, 0, prices, dp));
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 0, prices, dp);
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> val(n);
    for (auto &i : val)
        cin >> i;
    Solution sol;
    cout << sol.maxProfit(val) << endl;
}