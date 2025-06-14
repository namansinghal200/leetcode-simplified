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
    Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
    {
        if (!root || root == p || root == q)
        {
            return root;
        }
        Node *left = lowestCommonAncestor(root->left, p, q);
        Node *right = lowestCommonAncestor(root->right, p, q);

        if (left == NULL)
            return right;
        if (right == NULL)
            return left;
        return root;
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

    auto ans = sol.lowestCommonAncestor(root, root->left, root->right);
    cout << ans->data << endl;
}