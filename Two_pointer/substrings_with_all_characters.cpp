// Problem Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        unordered_map<int, int> m;
        int ans = 0;
        int i = 0;
        for (int j = 0; j < s.size(); j++)
        {
            m[s[j]]++;
            while (i < s.size() && m['a'] >= 1 && m['b'] >= 1 && m['c'] >= 1)
            {
                ans += (s.size() - j);
                m[s[i]]--;
                i++;
            }
        }
        return ans;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    cout << sol.numberOfSubstrings(s) << endl;
}