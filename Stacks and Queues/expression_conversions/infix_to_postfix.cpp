// Problem Link: https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string infixToPostfix(string &s)
    {
        // code here
        map<char, int> pres;
        pres['^'] = 3, pres['*'] = 2, pres['/'] = 2, pres['+'] = 1, pres['-'] = 1;

        string ans = "";
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
            {
                ans += s[i];
            }
            else if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() && pres[s[i]] <= pres[st.top()])
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    string ans = sol.infixToPostfix(s);
    cout << ans << endl;
}