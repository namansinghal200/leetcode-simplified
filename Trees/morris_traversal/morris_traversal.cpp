#include <bits/stdc++.h>
using namespace std;

// the main thing we have to make temperory links of the current node to its inorder predecessor.
// inorder and preorder are pretty similar, just one change in the condition of pushing the data.
// postorder is exactly same as preorder, just left and right are interchanged and the results are reversed at the end.
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
        Node *curr = root;
        while (curr)
        {
            if (curr->left == NULL)
            {
                ans.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                Node *prev = curr->left;
                while (prev->right && prev->right != curr)
                {
                    prev = prev->right;
                }
                if (prev->right == NULL)
                {
                    ans.push_back(curr->data);
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
    vector<int> inOrder(Node *root)
    {
        vector<int> ans;
        Node *curr = root;
        while (curr)
        {
            if (curr->left == NULL)
            {
                ans.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                Node *prev = curr->left;
                while (prev->right && prev->right != curr)
                {
                    prev = prev->right;
                }
                if (prev->right == NULL)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    ans.push_back(curr->data);
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
    vector<int> postOrder(Node *root)
    {
        vector<int> ans;
        Node *curr = root;
        while (curr)
        {
            if (curr->right == NULL)
            {
                ans.push_back(curr->data);
                curr = curr->left;
            }
            else
            {
                Node *prev = curr->right;
                while (prev->left && prev->left != curr)
                {
                    prev = prev->left;
                }
                if (prev->left == NULL)
                {
                    ans.push_back(curr->data);
                    prev->left = curr;
                    curr = curr->right;
                }
                else
                {
                    prev->left = NULL;
                    curr = curr->left;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(8);
    root->left->left->left = new Node(6);
    root->left->left->right = new Node(7);
    root->right->left->right = new Node(9);

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