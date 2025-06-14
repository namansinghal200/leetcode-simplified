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
    int height(Node *root, int &diameter)
    {
        if (root == NULL)
            return 0;
        int lh = height(root->left, diameter);
        int rh = height(root->right, diameter);
        diameter = max(diameter, lh + rh);
        return max(lh, rh) + 1;
    }
    int diameterOfBinaryTree(Node *root)
    {
        int diameter = 0;
        height(root, diameter);
        return diameter;
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

    auto ans2 = sol.diameterOfBinaryTree(root);
    cout << ans2 << endl;
}