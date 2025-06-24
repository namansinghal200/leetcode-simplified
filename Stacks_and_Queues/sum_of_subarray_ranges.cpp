// Problem Link: https://leetcode.com/problems/sum-of-subarray-ranges/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
#define int long long int
    int sumSubarrayMins(vector<int> &arr)
    {
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
            int prod = (lse[i] * rse[i]);
            prod = (prod * arr[i]);
            ans = (ans + prod);
        }
        return ans;
    }
    int sumSubarrayMaxs(vector<int> &arr)
    {
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
            while (!st.empty() && st.top().first < arr[i])
                st.pop();
            if (!st.empty())
                rse[i] = st.top().second - i;
            st.push({arr[i], i});
        }
        while (!st.empty())
            st.pop();
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top().first <= arr[i])
                st.pop();
            if (!st.empty())
                lse[i] = i - st.top().second;
            st.push({arr[i], i});
        }
        for (int i = 0; i < n; i++)
        {
            int prod = (lse[i] * rse[i]);
            prod = (prod * arr[i]);
            ans = (ans + prod);
        }
        return ans;
    }
#undef int
    long long subArrayRanges(vector<int> &nums)
    {
        vector<long long int> nums1;
        for (auto i : nums)
            nums1.push_back(i);
        return sumSubarrayMaxs(nums1) - sumSubarrayMins(nums1);
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
    cout << sol.subArrayRanges(nums) << endl;
}