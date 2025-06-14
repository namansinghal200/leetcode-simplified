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
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<Node *> q;
        q.push(root);
        int dir = 0;
        while (!q.empty())
        {
            int s = q.size();
            vector<int> level(s);
            for (int i = 0; i < s; i++)
            {
                Node *node = q.front();
                q.pop();
                if (dir)
                    level[s - 1 - i] = node->data;
                else
                    level[i] = node->data;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans.push_back(level);
            dir ^= 1;
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

    vector<vector<int>> ans2 = sol.levelOrder(root);
    for (auto i : ans2)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}