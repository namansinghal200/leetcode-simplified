#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int n, vector<int> &price, vector<int> &dp)
    {
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];

        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
            ans = max(ans, price[i] + solve(n - i - 1, price, dp));
        }
        return dp[n] = ans;
    }
    int cutRod(vector<int> &price)
    {
        // code here
        vector<int> dp(price.size(), -1);
        return solve(price.size() - 1, price, dp);
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    Solution sol;
    cout << sol.cutRod(v) << endl;
}