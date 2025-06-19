// Problem Link: https://www.geeksforgeeks.org/problems/most-frequent-word-in-an-array-of-strings3528/1
// like previous problems but use set here instead of vectors to store unique strings.

#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    Trie *links[26];
    set<string> vec;
    Trie()
    {
        for (int i = 0; i < 26; i++)
            links[i] = NULL;
    }
};
class Solution
{
public:
    vector<vector<string>> ans;
    Trie *root = new Trie();

    void insert(string &s)
    {
        Trie *temp = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (!temp->links[s[i] - 'a'])
                temp->links[s[i] - 'a'] = new Trie();
            temp = temp->links[s[i] - 'a'];
            temp->vec.insert(s);
        }
    }

    void search(string &s)
    {
        Trie *temp = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (!temp->links[s[i] - 'a'])
            {
                while (ans.size() < s.size())
                {
                    ans.push_back({"0"});
                }
                return;
            }
            temp = temp->links[s[i] - 'a'];
            vector<string> v(temp->vec.begin(), temp->vec.end());
            ans.push_back(v);
        }
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        for (int i = 0; i < n; i++)
        {
            insert(contact[i]);
        }
        search(s);
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    string s;
    cin >> s;

    Solution sol;
    auto ans = sol.displayContacts(n, arr, s);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}