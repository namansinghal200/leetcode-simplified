// Problem Link: https://leetcode.com/problems/word-search-ii/description/?envType=problem-list-v2&envId=trie

// The basic approach for this is, firstly insert all the words in the trie.
// Then for each letter of the board, check if it exists in the child of the root.
// If yes, keep searching for the next node till its available.
// Append the string to the answer if end is found.
// To avoid the hassle of maintaining a string, just use another pointer in the trie named str that stores the string at the endpoint.

#include <bits/stdc++.h>
using namespace std;

struct Trie
{
public:
    Trie *links[26];
    bool end;
    string str;
    Trie()
    {
        for (int i = 0; i < 26; i++)
            links[i] = NULL;
        end = false;
        str = "";
    }
};
class Solution
{
public:
    Trie *root = new Trie();
    vector<string> ans;

    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, -1, 0, 1};

    void insert(string s)
    {
        Trie *temp = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (!temp->links[s[i] - 'a'])
                temp->links[s[i] - 'a'] = new Trie();
            temp = temp->links[s[i] - 'a'];
        }
        temp->end = true;
        temp->str = s;
    }

    void dfs(int r, int c, vector<vector<char>> &board, vector<vector<bool>> &vis, Trie *root)
    {
        if (root->end)
        {
            ans.push_back(root->str);
            root->end = false;
        }

        for (int i = 0; i < 4; i++)
        {
            int newr = dr[i] + r;
            int newc = dc[i] + c;
            if (newr >= 0 && newr < board.size() && newc >= 0 && newc < board[0].size() && !vis[newr][newc] && root->links[board[newr][newc] - 'a'])
            {
                vis[newr][newc] = true;
                dfs(newr, newc, board, vis, root->links[board[newr][newc] - 'a']);
                vis[newr][newc] = false;
            }
        }
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        for (auto i : words)
        {
            insert(i);
        }
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (root->links[board[i][j] - 'a'])
                {
                    vis[i][j] = true;
                    dfs(i, j, board, vis, root->links[board[i][j] - 'a']);
                    vis[i][j] = false;
                }
            }
        }
        return ans;
    }
};

int main()
{
    int str;
    cin >> str;
    vector<string> v(str);
    for (int i = 0; i < str; i++)
        cin >> v[i];

    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    Solution sol;
    vector<string> ans = sol.findWords(board, v);

    for (auto i : ans)
        cout << i << endl;
}