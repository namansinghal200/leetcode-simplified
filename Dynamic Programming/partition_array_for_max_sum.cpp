#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int n, vector<int> &arr, vector<int> &dp, vector<vector<int>> &maxim, int k)
    {
        if (i == n)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int maxi = INT_MIN;
        for (int j = i; j < min(n, i + k); j++)
        {
            maxi = max(maxi, (j - i + 1) * maxim[i][j] + solve(j + 1, n, arr, dp, maxim, k));
        }

        return dp[i] = maxi;
    }
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<vector<int>> maxim(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            int maxi = arr[i];
            for (int j = i; j < n; j++)
            {
                if (arr[j] > maxi)
                    maxi = arr[j];
                maxim[i][j] = max(maxi, maxim[i][j]);
            }
        }

        vector<int> dp(n, -1);
        return solve(0, n, arr, dp, maxim, k);
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
    int ans = sol.maxSumAfterPartitioning(val, k);
    cout << ans << endl;
}