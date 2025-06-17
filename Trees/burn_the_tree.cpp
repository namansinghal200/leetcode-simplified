#include <bits/stdc++.h>
using namespace std;
#define TreeNode Node

// just find the parent and increase the count by one for each of the children and the parent.
// maintain a visited array

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
    Node *start = NULL;
    void findParent(Node *root, map<int, Node *> &parent, int target)
    {
        if (!root)
            return;
        if (root->data == target)
            start = root;
        if (root->left)
        {
            parent[root->left->data] = root;
            findParent(root->left, parent, target);
        }
        if (root->right)
        {
            parent[root->right->data] = root;
            findParent(root->right, parent, target);
        }
    }

    int minTime(Node *root, int target)
    {
        // Your code goes here
        map<int, Node *> parent;
        parent[root->data] = NULL;
        findParent(root, parent, target);
        unordered_set<int> vis;

        queue<pair<Node *, int>> q;
        q.push({start, 0});
        int ans = 0;

        while (!q.empty())
        {
            Node *node = q.front().first;
            int timee = q.front().second;
            // cout<<node->data<<endl;
            q.pop();

            if (vis.find(node->data) != vis.end())
                continue;
            vis.insert(node->data);
            ans = max(ans, timee);

            if (node->left)
                q.push({node->left, timee + 1});
            if (node->right)
                q.push({node->right, timee + 1});
            if (parent[node->data])
                q.push({parent[node->data], timee + 1});
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

    auto ans = sol.minTime(root, 2);
    cout << ans << endl;
}