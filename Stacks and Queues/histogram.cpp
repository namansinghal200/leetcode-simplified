// Problem Link: https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &arr)
    {
        int mod = 1e9 + 7;
        int ans = 0;
        int n = arr.size();
        vector<int> lse(n, -1), rse(n, n);
        stack<pair<int, int>> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top().first >= arr[i])
                st.pop();
            if (!st.empty())
                rse[i] = st.top().second;
            st.push({arr[i], i});
        }
        while (!st.empty())
            st.pop();
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top().first >= arr[i])
                st.pop();
            if (!st.empty())
                lse[i] = st.top().second;
            st.push({arr[i], i});
        }
        for (int i = 0; i < n; i++)
        {
            ans = max((rse[i] - lse[i] - 1) * arr[i], ans);
        }
        return ans;
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
    cout << sol.largestRectangleArea(nums) << endl;
}