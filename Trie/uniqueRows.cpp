// Problem Link: https://www.geeksforgeeks.org/problems/unique-rows-in-boolean-matrix/1

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

struct Trie
{
public:
    Trie *links[2];
    bool found;
    Trie()
    {
        for (int i = 0; i < 2; i++)
            links[i] = NULL;
        found = false;
    }
};
class Solution
{
public:
    // #define MAX 1000
    Trie *root = new Trie();
    void insert(int m, vector<int> &v)
    {
        Trie *temp = root;
        for (int i = 0; i < m; i++)
        {
            if (!temp->links[v[i]])
                temp->links[v[i]] = new Trie();
            temp = temp->links[v[i]];
        }
        temp->found = true;
    }

    bool search(int m, vector<int> &v)
    {
        Trie *temp = root;
        for (int i = 0; i < m; i++)
        {
            if (!temp->links[v[i]])
                return false;
            temp = temp->links[v[i]];
        }
        return temp->found;
    }

    vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col)
    {
        // Your code here
        vector<vector<int>> ans;
        for (int i = 0; i < row; i++)
        {
            vector<int> v(M[i], M[i] + col);
            if (!search(col, v))
            {
                ans.push_back(v);
                insert(col, v);
            }
        }

        return ans;
    }
};

int main()
{
    int row, col;
    cout << "getting input" << endl;
    cin >> row >> col;
    cout << row << " " << col << endl;
    int M[MAX][MAX];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> M[i][j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    Solution sol;
    vector<vector<int>> ans = sol.uniqueRow(M, row, col);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}