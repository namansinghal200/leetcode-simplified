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
    int solve(Node *root, int k, int sum, map<int, int> &m)
    {
        if (!root)
            return 0;

        int count = 0;
        sum += root->data;
        if (sum == k)
            count++;
        count += m[sum - k];
        m[sum]++;

        count += solve(root->left, k, sum, m);
        count += solve(root->right, k, sum, m);
        m[sum]--;

        return count;
    }
    int sumK(Node *root, int k)
    {
        // code here
        map<int, int> m;
        return solve(root, k, 0, m);
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

    auto ans = sol.sumK(root, 6);
    cout << ans << endl;
}