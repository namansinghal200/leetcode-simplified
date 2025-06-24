// Problem Link: https://leetcode.com/problems/asteroid-collision/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &nums)
    {
        stack<int> st;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
                st.push(nums[i]);
            else if (st.empty())
                ans.push_back(nums[i]);
            else
            {
                while (!st.empty() && abs(st.top()) < abs(nums[i]))
                    st.pop();
                if (!st.empty() && abs(st.top()) == abs(nums[i]))
                    st.pop();
                else if (st.empty() || abs(st.top()) < abs(nums[i]))
                {
                    ans.push_back(nums[i]);
                }
            }
        }
        stack<int> st2;
        while (!st.empty())
        {
            st2.push(st.top());
            st.pop();
        }
        while (!st2.empty())
        {
            ans.push_back(st2.top());
            st2.pop();
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
    vector<int> v1 = sol.asteroidCollision(nums);
    sol.print(v1);
}