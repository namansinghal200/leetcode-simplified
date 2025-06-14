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
    int solve(Node *root, int &maxi)
    {
        if (root == NULL)
            return 0;
        int lsum = max(0, solve(root->left, maxi));
        int rsum = max(0, solve(root->right, maxi));
        int val = root->data;
        maxi = max(maxi, lsum + rsum + val);
        return max(lsum, rsum) + val;
    }
    int maxPathSum(Node *root)
    {
        int maxi = INT_MIN;
        solve(root, maxi);
        return maxi;
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

    auto ans = sol.maxPathSum(root);
    cout << ans << endl;
}