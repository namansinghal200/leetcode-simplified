#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
public:
    vector<vector<int>> verticalOrder(Node *root)
    {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> m;
        if (root == NULL)
            return ans;
        queue<pair<Node *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            Node *node = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            m[x][y].insert(node->data);
            if (node->left)
                q.push({node->left, {x - 1, y + 1}});
            if (node->right)
                q.push({node->right, {x + 1, y + 1}});
        }
        for (auto i : m)
        {
            vector<int> col;
            for (auto j : i.second)
            {
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->left->left->left = new Node(7);

    Solution sol;

    vector<vector<int>> ans2 = sol.verticalOrder(root);
    for (auto i : ans2)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}