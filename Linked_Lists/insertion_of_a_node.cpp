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
    Node *insertAtBeginning(Node *head, int x)
    {
        if (!head)
        {
            return new Node(x);
        }
        Node *temp = new Node(x);
        temp->next = head;
        return temp;
    }

    Node *insertAfterNode(Node *head, int x, int y)
    {
        Node *temp = head;
        while (temp->data != x)
            temp = temp->next;
        if (temp == NULL)
            return head;
        Node *newNode = new Node(y, temp->next);
        temp->next = newNode;
        return head;
    }

    Node *insertAtPosition(Node *head, int x, int y)
    {
        Node *temp = head, *prev = NULL;
        while (temp && (--x))
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            return head;
        Node *newNode = new Node(y, temp);
        prev->next = newNode;
        return head;
    }

    Node *insertBeforeNode(Node *head, int x, int y)
    {
        Node *temp = head, *prev = NULL;
        while (temp && temp->data != x)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            return head;
        Node *newNode = new Node(y, temp);
        prev->next = newNode;
        return head;
    }

    Node *insertAtEnd(Node *head, int x)
    {
        if (!head)
        {
            return new Node(x);
        }
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
};

int main()
{
    Node *head = new Node(1);
    Solution sol;
    head = sol.insertAtBeginning(head, 3);
    head = sol.insertAtBeginning(head, 2);
    head = sol.insertAfterNode(head, 3, 7);
    head = sol.insertAtPosition(head, 2, 4);
    head = sol.insertBeforeNode(head, 7, 5);
    head = sol.insertAtEnd(head, 9);
    sol.print(head);
}