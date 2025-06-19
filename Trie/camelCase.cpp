// Problem Link: https://www.geeksforgeeks.org/problems/camelcase-pattern-matching2259/1

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
    Trie *root = new Trie();
    void insert(string &s)
    {
        Trie *temp = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] < 'A' || s[i] > 'Z')
                continue;
            if (!temp->links[s[i] - 'A'])
                temp->links[s[i] - 'A'] = new Trie();
            temp = temp->links[s[i] - 'A'];
            temp->v.push_back(s);
        }
    }

    vector<string> search(string &s)
    {
        Trie *temp = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (!temp->links[s[i] - 'A'])
                return {};
            temp = temp->links[s[i] - 'A'];
        }
        return temp->v;
    }
    vector<string> camelCase(vector<string> &arr, string &pat)
    {
        // code here
        for (auto i : arr)
        {
            insert(i);
        }

        return search(pat);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    string pat;
    cin >> pat;

    Solution sol;
    vector<string> ans = sol.camelCase(arr, pat);
    for (auto i : ans)
        cout << i << endl;
}