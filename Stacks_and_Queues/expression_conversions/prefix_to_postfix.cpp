// Problem Link: https://www.geeksforgeeks.org/problems/prefix-to-postfix-conversion/1

// start traversing the prefix string from behind.
// append the operands in the stack.
// if you get an operator opr, take op1 and op2 out from stack and push back op1+op2+opr.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string postToPre(string s)
    {
        // Write your code here
        stack<string> st;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
            {
                st.push(string(1, s[i]));
            }
            else
            {
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();

                st.push(s1 + s2 + s[i]);
            }
        }
        return st.top();
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    string ans = sol.postToPre(s);
    cout << ans << endl;
}