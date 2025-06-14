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
    void preorder(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        ans.push_back(root->data);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    vector<int> preorderTraversal(Node *root)
    {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
    void postorder(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->data);
    }
    vector<int> postorderTraversal(Node *root)
    {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
    void inorder(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    vector<int> inorderTraversal(Node *root)
    {
        vector<int> ans;
        inorder(root, ans);
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
    vector<int> ans = sol.preorderTraversal(root);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    ans = sol.postorderTraversal(root);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    ans = sol.inorderTraversal(root);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}