#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *next;
    int data;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
    Node(int x, Node *y)
    {
        data = x;
        next = y;
    }
};

class Solution
{
public:
    Node *insertAtEnd(Node *head, int x)
    {
        if (!head)
            return new Node(x);
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new Node(x);
        return head;
    }

    void print(Node *head)
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node *merge(Node *left, Node *right)
    {
        Node *dummy = new Node(-1);
        Node *temp = dummy;
        while (left && right)
        {
            if (left->data > right->data)
            {
                temp->next = right;
                right = right->next;
            }
            else
            {
                temp->next = left;
                left = left->next;
            }
            temp = temp->next;
        }
        if (left)
            temp->next = left;
        if (right)
            temp->next = right;
        return dummy->next;
    }
    Node *sort(Node *head)
    {
        if (!head || !head->next)
            return head;

        Node *slow = head, *fast = head, *prev = NULL;
        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        Node *right = sort(slow);
        Node *left = sort(head);
        // print(left);
        // print(right);
        return merge(left, right);
    }
};

int main()
{
    Node *head = NULL;
    Solution sol;
    head = sol.insertAtEnd(head, 9);
    head = sol.insertAtEnd(head, 3);
    head = sol.insertAtEnd(head, 2);
    head = sol.insertAtEnd(head, 6);
    head = sol.insertAtEnd(head, 7);
    head = sol.insertAtEnd(head, 8);

    sol.print(head);
    head = sol.sort(head);
    sol.print(head);
}