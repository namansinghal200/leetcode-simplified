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
    map<int, int> inm;
    TreeNode *solve(int posts, int poste, int ins, int ine, vector<int> &inorder, vector<int> &postorder)
    {
        if (posts > poste || ins > ine)
            return NULL;
        TreeNode *root = new TreeNode(postorder[poste]);

        int ind = inm[postorder[poste]];
        int numsleft = ind - ins;

        root->left = solve(posts, posts + numsleft - 1, ins, ind - 1, inorder, postorder);
        root->right = solve(posts + numsleft, poste - 1, ind + 1, ine, inorder, postorder);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = postorder.size();
        for (int i = 0; i < n; i++)
            inm[inorder[i]] = i;
        TreeNode *root = solve(0, n - 1, 0, n - 1, inorder, postorder);
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
    vector<int> inorder = {9, 3, 15, 20, 7}, postorder = {9, 15, 20, 7, 3};
    Solution sol;
    auto tree = sol.buildTree(inorder, postorder);
    auto intrav = sol.inorderTraversal(tree);
    for (auto i : intrav)
        cout << i << " ";
    cout << endl;
}