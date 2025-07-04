#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int knapSack(vector<int> &val, vector<int> &wt, int W)
    {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1));

        for (int i = wt[0]; i <= W; i++)
        {
            dp[0][i] = (i / wt[0]) * val[0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                int notTake = dp[i - 1][j];

                int take = INT_MIN;
                if (wt[i] <= j)
                    take = dp[i][j - wt[i]] + val[i];

                dp[i][j] = max(take, notTake);
            }
        }
        return dp[n - 1][W];
    }
};
int main()
{
    int n, sum;
    cin >> n >> sum;
    vector<int> val(n), wt(n);
    for (auto &i : val)
        cin >> i;
    for (auto &i : wt)
        cin >> i;
    Solution sol;
    cout << sol.knapSack(val, wt, sum) << endl;
}