// Problem Link: https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestKSubstr(string &s, int k)
    {
        // your code here
        map<char, int> m;
        int ans = -1;
        int i = 0;
        for (int j = 0; j < s.size(); j++)
        {
            m[s[j]]++;
            while (i < s.size() && m.size() > k)
            {
                m[s[i]]--;
                if (m[s[i]] == 0)
                    m.erase(s[i]);
                i++;
            }
            if (m.size() == k)
                ans = max(ans, j - i + 1);
        }
        return ans;
    }
};

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    Solution sol;
    cout << sol.longestKSubstr(s, k) << endl;
}