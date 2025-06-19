// code to get all the substring of a string using Trie

#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    Trie *links[26];
    vector<string> v;
    Trie()
    {
        for (int i = 0; i < 26; i++)
            links[i] = NULL;
    }
};

class Solution
{
public:
    pair<vector<string>, int> getSubstrings(string s)
    {
        Trie *root = new Trie();
        vector<string> ans;
        int count = 0;

        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            string str = "";
            Trie *temp = root;
            for (int j = i; j < n; j++)
            {
                str += s[j];
                if (!temp->links[s[j] - 'a'])
                {
                    temp->links[s[j] - 'a'] = new Trie();
                    ans.push_back(str);
                    count++;
                }
                temp = temp->links[s[j] - 'a'];
            }
        }
        return {ans, count};
    }
};
int main()
{
    string s;
    cin >> s;

    Solution sol;
    auto ans = sol.getSubstrings(s);
    for (auto i : ans.first)
        cout << i << " ";
    cout << endl;
    cout << ans.second << endl;
}