// Problem Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &nums, int k)
    {
        int ans = accumulate(nums.begin(), nums.begin() + k, 0);
        int temp = ans;
        for (int j = k - 1; j >= 0; j--)
        {
            temp -= nums[j];
            temp += nums[nums.size() - 1 - (k - 1) + j];
            ans = max(ans, temp);
        }
        return ans;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    Solution sol;
    cout << sol.maxScore(v, k) << endl;
}