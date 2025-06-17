#include <bits/stdc++.h>
using namespace std;

// get the left nodes, then the leaves, then the right nodes.
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
    void getLeft(Node *root, vector<int> &ans)
    {
        if (!root || (!root->left && !root->right))
            return;
        ans.push_back(root->data);
        if (root->left)
            getLeft(root->left, ans);
        else if (root->right)
            getLeft(root->right, ans);
    }
    void getLeaves(Node *root, vector<int> &ans)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            ans.push_back(root->data);
            return;
        }
        getLeaves(root->left, ans);
        getLeaves(root->right, ans);
    }
    void getRight(Node *root, vector<int> &ans)
    {
        if (!root || (!root->left && !root->right))
            return;
        if (root->right)
            getRight(root->right, ans);
        else if (root->left)
            getRight(root->left, ans);
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root)
    {
        // code here
        vector<int> ans;
        if (!root)
            return ans;
        if (root->left || root->right)
            ans.push_back(root->data);
        getLeft(root->left, ans);
        getLeaves(root, ans);
        getRight(root->right, ans);
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

    auto ans = sol.boundaryTraversal(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}