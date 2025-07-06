// Problem Link: https://leetcode.com/problems/house-robber/
// Problem Link: https://leetcode.com/problems/house-robber-ii

// in house robber 2, do dp twice, once on ignoring first element, again on ignoring the last element and get the max.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        if (n > 1)
            dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    Solution sol;
    cout << sol.rob(v) << endl;
}