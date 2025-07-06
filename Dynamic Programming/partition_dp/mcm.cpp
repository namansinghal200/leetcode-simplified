#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (i == j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = INT_MAX;
        for (int k = i; k < j; k++)
        {
            mini = min(mini, solve(i, k, arr, dp) + solve(k + 1, j, arr, dp) + arr[i - 1] * arr[k] * arr[j]);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(vector<int> &arr)
    {
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));
        return solve(1, arr.size() - 1, arr, dp);
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> val(n + 1);
    for (auto &i : val)
        cin >> i;
    Solution sol;
    int ans = sol.matrixMultiplication(val);
    cout << ans << endl;
}