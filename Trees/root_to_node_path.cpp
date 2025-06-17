#include <bits/stdc++.h>
using namespace std;

// a recursive search from the root to the given node.
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
    bool check(Node *root, int target, vector<int> &ans)
    {
        if (!root)
            return false;
        ans.push_back(root->data);
        if (root->data == target)
        {
            return true;
        }
        if (check(root->left, target, ans) || check(root->right, target, ans))
            return true;
        ans.pop_back();
        return false;
    }
    vector<int> getPath(Node *root, int target)
    {
        vector<int> ans;
        if (!check(root, target, ans))
            return {-1};
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

    auto ans = sol.getPath(root, 1);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}