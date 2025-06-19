// Problem Link: https://leetcode.com/problems/valid-parentheses/submissions/1669647712/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if (st.empty())
                    return false;
                char ch = st.top();
                if ((s[i] == ')' && ch != '(') || (s[i] == ']' && ch != '[') || (s[i] == '}' && ch != '{'))
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    cout << sol.isValid(s) << endl;
}