// just find lca and the sum of distance from lca to either of the nodes is the answer
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
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node *findlca(Node *root, int a, int b)
    {
        if (!root || root->data == a || root->data == b)
            return root;
        Node *left = findlca(root->left, a, b);
        Node *right = findlca(root->right, a, b);
        if (left && right)
            return root;
        if (!left)
            return right;
        return left;
    }
    int dist(Node *lca, int x, int level)
    {
        if (!lca)
            return -1;
        if (lca->data == x)
            return level;
        int left = dist(lca->left, x, level + 1);
        if (left == -1)
            return dist(lca->right, x, level + 1);
        return left;
    }
    int findDist(Node *root, int a, int b)
    {
        // Your code here
        Node *lca = findlca(root, a, b);
        return dist(lca, a, 0) + dist(lca, b, 0);
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

    auto ans = sol.findDist(root, 7, 4);
    cout << ans << endl;
}