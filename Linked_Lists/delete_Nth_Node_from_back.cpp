#include <bits/stdc++.h>
using namespace std;

// slow and fast pointer
// move the fast pointer ahead by N indpendently, then  move both together

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

    Node *reverse(Node *head)
    {
        if (!head)
            return head;
        Node *prev = NULL, *curr = head;
        while (curr)
        {
            Node *nextt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextt;
        }
        return prev;
    }

    Node *deleteNthNodeFromBack(Node *head, int pos)
    {
        Node *first = head, *second = head;
        for (int i = 0; i < pos; i++)
        {
            first = first->next;
        }
        if (first == NULL)
            return head->next;
        while (first->next)
        {
            second = second->next;
            first = first->next;
        }
        second->next = second->next->next;
        return head;
    }
};

int main()
{
    Node *head = NULL;
    Solution sol;
    head = sol.insertAtEnd(head, 9);
    head = sol.insertAtEnd(head, 3);
    head = sol.insertAtEnd(head, 2);
    head = sol.insertAtEnd(head, 2);
    head = sol.insertAtEnd(head, 3);
    head = sol.insertAtEnd(head, 9);

    head = sol.deleteNthNodeFromBack(head, 6);
    sol.print(head);
}