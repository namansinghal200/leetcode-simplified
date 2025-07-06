#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), prev(n, -1);
        int ans = -1;
        int last = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > ans)
            {
                ans = dp[i];
                last = i;
            }
        }

        vector<int> anss;
        while (last != -1)
        {
            anss.push_back(nums[last]);
            last = prev[last];
        }
        reverse(anss.begin(), anss.end());
        return anss;
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
    vector<int> ans = sol.largestDivisibleSubset(val);
    for (auto i : ans)
        cout << i << " ";
}