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
    Node *sort012(Node *head)
    {
        Node *zero = new Node(-1), *one = new Node(-1), *two = new Node(-1);
        Node *zerop = zero, *onep = one, *twop = two, *temp = head;

        while (temp)
        {
            if (temp->data == 0)
            {
                zerop->next = temp;
                zerop = zerop->next;
            }
            else if (temp->data == 1)
            {
                onep->next = temp;
                onep = onep->next;
            }
            else
            {
                twop->next = temp;
                twop = twop->next;
            }
            temp = temp->next;
        }

        if (one->next)
        {
            zerop->next = one->next;
        }
        else
        {
            zerop->next = two->next;
        }
        onep->next = two->next;
        twop->next = NULL;
        return zero->next;
    }
};

int main()
{
    Node *head = NULL;
    Solution sol;
    head = sol.insertAtEnd(head, 2);
    head = sol.insertAtEnd(head, 0);
    head = sol.insertAtEnd(head, 2);
    head = sol.insertAtEnd(head, 0);
    head = sol.insertAtEnd(head, 2);
    head = sol.insertAtEnd(head, 2);

    sol.print(head);
    head = sol.sort012(head);
    sol.print(head);
}