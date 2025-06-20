// Problem Link: https://leetcode.com/problems/remove-k-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string nums, int k)
    {
        stack<char> st;
        for (int i = 0; i < nums.size(); i++)
        {
            while (k && !st.empty() && st.top() > nums[i])
            {
                st.pop();
                k--;
            }
            st.push(nums[i]);
        }
        string ans = "";
        while (!st.empty() && k)
        {
            st.pop();
            k--;
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        while (ans.size() && ans.back() == '0')
            ans.pop_back();
        if (ans.size() == 0)
            return "0";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    Solution sol;
    cout << sol.removeKdigits(s, k) << endl;
}