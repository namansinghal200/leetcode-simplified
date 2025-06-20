// Problem Link: https://leetcode.com/problems/trapping-rain-water/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap2(vector<int> &height)
    {
        int n = height.size();
        vector<int> nge(n, -1), pge(n, -1);
        int ng = -1, pg = -1;
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            nge[i] = ng;
            ng = max(ng, height[i]);
        }

        for (int i = 0; i < n; i++)
        {
            pge[i] = pg;
            pg = max(pg, height[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (min(nge[i], pge[i]) > height[i])
                ans += min(nge[i], pge[i]) - height[i];
        }
        return ans;
    }
    int trap(vector<int> &height)
    {
        int n = height.size();
        int l = 0, r = n - 1;
        int ans = 0;
        int lmax = 0, rmax = 0;

        while (l <= r)
        {
            if (height[l] <= height[r])
            {
                if (height[l] >= lmax)
                {
                    lmax = height[l];
                }
                else
                {
                    ans += lmax - height[l];
                }
                l++;
            }
            else
            {
                if (height[r] >= rmax)
                {
                    rmax = height[r];
                }
                else
                {
                    ans += rmax - height[r];
                }
                r--;
            }
        }
        return ans;
    }
    void print(vector<int> &v)
    {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution sol;
    int v1 = sol.trap(nums);
    int v2 = sol.trap(nums);
    cout << v1 << " " << v2 << endl;
}