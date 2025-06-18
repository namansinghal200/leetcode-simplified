// Problem Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include <bits/stdc++.h>
using namespace std;
#define TreeNode Node
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
    map<int, int> m;
    TreeNode *solve(int pres, int pree, int ins, int ine, vector<int> &preorder, vector<int> &inorder)
    {
        if (pres > pree || ins > ine)
            return NULL;
        TreeNode *root = new TreeNode(preorder[pres]);
        int ind = m[preorder[pres]];
        int numsleft = ind - ins;
        root->left = solve(pres + 1, pres + numsleft, ins, ind - 1, preorder, inorder);
        root->right = solve(pres + numsleft + 1, pree, ind + 1, ine, preorder, inorder);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        for (int i = 0; i < n; i++)
            m[inorder[i]] = i;
        TreeNode *root = solve(0, n - 1, 0, n - 1, preorder, inorder);
        return root;
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
    vector<int> inorder = {9, 3, 15, 20, 7}, preorder = {3, 9, 20, 15, 7};
    Solution sol;
    auto tree = sol.buildTree(preorder, inorder);
    auto intrav = sol.inorderTraversal(tree);
    for (auto i : intrav)
        cout << i << " ";
    cout << endl;
}