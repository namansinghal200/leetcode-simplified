// Problem Link: https://leetcode.com/problems/sum-of-subarray-minimums/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int mod = 1e9 + 7;
        int ans = 0;
        int n = arr.size();
        vector<int> lse(n), rse(n);
        for (int i = 0; i < n; i++)
        {
            lse[i] = i + 1;
            rse[i] = n - i;
        }
        stack<pair<int, int>> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top().first > arr[i])
                st.pop();
            if (!st.empty())
                rse[i] = st.top().second - i;
            st.push({arr[i], i});
        }
        while (!st.empty())
            st.pop();
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top().first >= arr[i])
                st.pop();
            if (!st.empty())
                lse[i] = i - st.top().second;
            st.push({arr[i], i});
        }
        for (int i = 0; i < n; i++)
        {
            long long int prod = (lse[i] * rse[i]) % mod;
            prod = (prod * arr[i]) % mod;
            ans = (ans + prod) % mod;
        }
        return ans % mod;
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
    int v1 = sol.sumSubarrayMins(nums);
    cout << v1 << endl;
}