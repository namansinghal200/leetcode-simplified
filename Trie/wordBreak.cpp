#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    class Trie
    {
    public:
        Trie *child[26];
        bool isEnd = false;
    };

    void insert(string &word, Trie *root)
    {
        Trie *cur = root;
        for (auto &ch : word)
        {
            if (!cur->child[ch - 'a'])
                cur->child[ch - 'a'] = new Trie();
            cur = cur->child[ch - 'a'];
        }
        cur->isEnd = true;
    }

    bool search(string &word, Trie *root)
    {
        Trie *cur = root;
        for (auto &ch : word)
        {
            if (!cur->child[ch - 'a'])
                return false;
            cur = cur->child[ch - 'a'];
        }
        return cur->isEnd;
    }

    int dp[305][305];
    bool solve(string &s, Trie *root, int n, int start)
    {
        if (start == n)
            return true;
        if (dp[start][n] != -1)
            return dp[start][n];
        for (int i = start; i < n; ++i)
        {
            string str = s.substr(start, i - start + 1);
            if (search(str, root))
            {
                if (solve(s, root, n, i + 1))
                    return dp[start][n] = true;
            }
        }
        return dp[start][n] = false;
    }

    bool wordBreak(string &s, vector<string> &wordDict)
    {
        Trie *root = new Trie();
        for (auto &word : wordDict)
            insert(word, root);
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(s, root, n, 0);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<string> dict(n);
    for (auto &i : dict)
        cin >> i;

    int m;
    cin >> m;
    Solution sol;
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        cout << (sol.wordBreak(s, dict) ? "YES" : "NO") << endl;
    }

    return 0;
}