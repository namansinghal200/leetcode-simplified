// Problem Link: https://leetcode.com/problems/max-consecutive-ones-iii/description/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int c0 = 0, i = 0;
        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] == 0)
                c0++;
            while (c0 > k)
            {
                if (nums[i] == 0)
                    c0--;
                i++;
            }
            ans = max(ans, j - i + 1);
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
    cout << sol.longestOnes(v, k) << endl;
}