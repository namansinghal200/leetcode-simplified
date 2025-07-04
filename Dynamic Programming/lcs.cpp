#include <bits/stdc++.h>
using namespace std;

// to get longest common substring, just set dp[i][j]=0 in the else case.
// to get longest palindromic subsequence, find the lcs of the string with its reverse
// to get the number of characters to add to make string palandromic, substracting the lps from the string length.
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    Solution sol;
    cout << sol.longestCommonSubsequence(s1, s2) << endl;
}