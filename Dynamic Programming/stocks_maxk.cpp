#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int i, int j, int k, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (i == prices.size() || k < 0)
            return 0;
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        if (j == 1)
        {
            return dp[i][j][k] = max(solve(i + 1, j, k, prices, dp), prices[i] + solve(i + 1, 0, k - 1, prices, dp));
        }
        return dp[i][j][k] = max(solve(i + 1, j, k, prices, dp), -prices[i] + solve(i + 1, 1, k, prices, dp));
    }
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k, -1)));
        return solve(0, 0, k - 1, prices, dp);
    }
};
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> val(n);
    for (auto &i : val)
        cin >> i;
    Solution sol;
    cout << sol.maxProfit(k, val) << endl;
}