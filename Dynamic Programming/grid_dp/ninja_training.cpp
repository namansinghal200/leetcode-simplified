// Problem Link: https://www.geeksforgeeks.org/problems/geeks-training/0

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumPoints(vector<vector<int>> &arr)
    {
        // Code here
        vector<vector<int>> dp(arr.size(), vector<int>(3, 0));
        dp[0] = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j == 0)
                    dp[i][j] = max(dp[i - 1][1], dp[i - 1][2]) + arr[i][j];
                else if (j == 1)
                    dp[i][j] = max(dp[i - 1][0], dp[i - 1][2]) + arr[i][j];
                else if (j == 2)
                    dp[i][j] = max(dp[i - 1][1], dp[i - 1][0]) + arr[i][j];
            }
        }

        return *max_element(dp[arr.size() - 1].begin(), dp[arr.size() - 1].end());
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> v[i][j];

    Solution sol;
    cout << sol.maximumPoints(v) << endl;
}