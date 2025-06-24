// Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0, ans = 0;
        map<char, int> v;
        for (int j = 0; j < s.size(); j++)
        {
            v[s[j]]++;
            while (i < s.size() && v[s[j]] > 1)
            {
                v[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;
}