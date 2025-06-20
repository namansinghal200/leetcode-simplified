// Problem Link: https://leetcode.com/problems/next-greater-element-i/
// Problem Link: https://leetcode.com/problems/next-greater-element-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nge(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> nge(n, -1);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i])
                st.pop();
            if (!st.empty())
                nge[i] = st.top();
            st.push(nums[i]);
        }
        return nge;
    }

    vector<int> ngeCirc(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> nge(n, -1);
        for (int i = (2 * n - 1); i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i % n])
                st.pop();
            if (!st.empty())
                nge[i % n] = st.top();
            st.push(nums[i % n]);
        }
        return nge;
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
    vector<int> v1 = sol.nge(nums);
    vector<int> v2 = sol.ngeCirc(nums);
    sol.print(v1);
    sol.print(v2);
}