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
    void findParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left)
            {
                q.push(node->left);
                parent[node->left] = node;
            }
            if (node->right)
            {
                q.push(node->right);
                parent[node->right] = node;
            }
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent;
        findParents(root, parent);

        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(target);
        int curr = 0;
        visited[target] = true;
        while (!q.empty())
        {
            int size = q.size();
            if (curr++ == k)
                break;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left && !visited[node->left])
                {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if (node->right && !visited[node->right])
                {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if (parent[node] && !visited[parent[node]])
                {
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            ans.push_back(q.front()->data);
            q.pop();
        }
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

    auto ans = sol.distanceK(root, root->left, 1);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}