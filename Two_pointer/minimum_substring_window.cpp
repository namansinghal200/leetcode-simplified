// Problem Link: https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        map<char, int> m, m2;
        for (int i = 0; i < t.size(); i++)
            m[t[i]]++;

        if (s.size() < t.size())
            return "";
        int i = 0, len = s.size() + 1;
        int left = -1;
        for (int j = 0; j < s.size(); j++)
        {
            m2[s[j]]++;
            while (i < s.size() && m2[s[i]] > m[s[i]])
            {
                m2[s[i]]--;
                i++;
            }
            bool allowed = true;
            for (auto p : m)
            {
                if (p.second > m2[p.first])
                {
                    allowed = false;
                    break;
                }
            }
            // cout<<i<<" "<<j<<endl;
            if (allowed && j - i + 1 < len)
            {
                len = j - i + 1;
                left = i;
            }
        }
        if (left != -1)
        {
            cout << left << " " << len << endl;
            return s.substr(left, len);
        }
        return "";
    }
};

int main()
{
    string s, t;
    cin >> s >> t;

    Solution sol;
    cout << sol.minWindow(s, t) << endl;
}