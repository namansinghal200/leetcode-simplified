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
    vector<int> bottomView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        map<int, int> m;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            Node *node = q.front().first;
            int ind = q.front().second;
            q.pop();

            m[ind] = node->data;
            if (node->left)
                q.push({node->left, ind - 1});
            if (node->right)
                q.push({node->right, ind + 1});
        }
        for (auto i : m)
            ans.push_back(i.second);
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

    vector<int> ans2 = sol.bottomView(root);
    for (auto i : ans2)
    {

        cout << i << " ";
    }
}