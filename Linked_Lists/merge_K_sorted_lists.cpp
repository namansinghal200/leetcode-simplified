#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *next;
    Node *child;
    int data;
    Node(int x)
    {
        data = x;
        next = NULL;
        child = NULL;
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
            temp = temp->child;
        }
        cout << endl;
    }

    void printOriginal(Node *head)
    {
        Node *temp = head;
        while (temp)
        {
            Node *temp2 = temp;
            while (temp2)
            {
                cout << temp2->data << " ";
                temp2 = temp2->child;
            }
            cout << endl;
            temp = temp->next;
        }
    }
    Node *merge(Node *left, Node *right)
    {
        Node *dummy = new Node(-1);
        Node *temp = dummy;
        while (left && right)
        {
            if (left->data > right->data)
            {
                temp->child = right;
                right = right->child;
            }
            else
            {
                temp->child = left;
                left = left->child;
            }
            temp = temp->child;
        }

        while (right)
        {
            temp->child = right;
            right = right->child;
            temp = temp->child;
        }

        while (left)
        {
            temp->child = left;
            left = left->child;
            temp = temp->child;
        }

        return dummy->child;
    }

    Node *mergeList(Node *head)
    {
        if (!head || !head->next)
            return head;
        Node *mergeNext = mergeList(head->next);
        head = merge(head, mergeNext);
        return head;
    }
};

int main()
{
    Node *head = new Node(5);
    head->child = new Node(14);

    head->next = new Node(4);
    head->next->child = new Node(10);

    head->next->next = new Node(12);
    head->next->next->child = new Node(13);
    head->next->next->child->child = new Node(15);
    head->next->next->child->child->child = new Node(20);

    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);
    head->next->next->next->child->child = new Node(31);

    Solution sol;
    sol.printOriginal(head);
    Node *ll = sol.mergeList(head);
    sol.print(ll);
}