// reverse the infix string and interchange all the brackets ('(' to ')' and vice-versa)
// now do infix to postfix on this
// reverse the answer obtained

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
    string infixToPrefix(string &s)
    {
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                s[i] = ')';
            else if (s[i] == ')')
                s[i] = '(';
        }
        string ans = infixToPostfix(s);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    string ans = sol.infixToPrefix(s);
    cout << ans << endl;
}