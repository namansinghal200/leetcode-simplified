// Problem Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

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
    Node *flatten(Node *root)
    {
        vector<int> ans;
        Node *curr = root;
        while (curr)
        {
            if (curr->left)
            {
                Node *prev = curr->left;
                while (prev->right)
                    prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
        return root;
    }
};
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(8);
    root->left->left->left = new Node(6);
    root->left->left->right = new Node(7);
    root->right->left->right = new Node(9);

    Solution sol;

    Node *ans = sol.flatten(root);
    while (root)
    {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}