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
    vector<int> preOrder(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        stack<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *node = q.top();
            q.pop();

            ans.push_back(node->data);
            if (node->right)
                q.push(node->right);
            if (node->left)
                q.push(node->left);
        }
        return ans;
    }
    vector<int> inOrder(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        stack<Node *> q;

        Node *curr = root;
        while (!q.empty() || curr)
        {
            while (curr)
            {
                q.push(curr);
                curr = curr->left;
            }

            curr = q.top();
            q.pop();
            ans.push_back(curr->data);
            curr = curr->right;
        }

        return ans;
    }
    vector<int> postOrder(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;

        stack<Node *> st;
        Node *curr = root;
        while (!st.empty() || curr)
        {
            while (curr)
            {
                if (curr->right)
                    st.push(curr->right);
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            if (!st.empty() && curr->right && st.top() == curr->right)
            {
                st.pop();
                st.push(curr);
                curr = curr->right;
            }
            else
            {
                ans.push_back(curr->data);
                curr = NULL;
            }
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

    vector<int> ans2 = sol.preOrder(root);
    for (auto i : ans2)
    {
        cout << i << " ";
    }
    cout << endl;
    ans2 = sol.inOrder(root);
    for (auto i : ans2)
    {
        cout << i << " ";
    }
    cout << endl;
    ans2 = sol.postOrder(root);
    for (auto i : ans2)
    {
        cout << i << " ";
    }
    cout << endl;
}