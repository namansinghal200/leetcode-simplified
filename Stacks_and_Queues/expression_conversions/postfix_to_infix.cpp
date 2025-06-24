// Problem Link: https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1

// start traversing the postfix string from the front.
// append the operands in the stack.
// if you get an operator opr, take op1 and op2 out from stack and push back (+op2+opr+op1+).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string postToInfix(string s)
    {
        // Write your code here
        stack<string> st;
        for (int i = 0; i < s.size(); i++)
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

                st.push("(" + s2 + s[i] + s1 + ")");
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
    string ans = sol.postToInfix(s);
    cout << ans << endl;
}