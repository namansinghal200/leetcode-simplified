#include <bits/stdc++.h>
using namespace std;

// L0->L1->L2->L3->L4 ---> L0->L4->L1->L3->L2
// just reverse the second half of the list and merge. Find the second half using tortoise-hare.

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

    Node *rotateRight(Node *head, int k)
    {
        Node *temp = head;
        int len = 1;
        while (temp->next)
        {
            temp = temp->next;
            len++;
        }
        temp->next = head;
        k = k % len;
        int end = len - k;

        while (end--)
            temp = temp->next;
        head = temp->next;
        temp->next = NULL;
        return head;
    }

    Node *rotateLeft(Node *head, int k)
    {
        Node *temp = head;
        int len = 1;
        while (temp->next)
        {
            temp = temp->next;
            len++;
        }
        temp->next = head;
        k = k % len;
        int end = k;

        while (end--)
            temp = temp->next;
        head = temp->next;
        temp->next = NULL;
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
    head = sol.insertAtEnd(head, 6);
    head = sol.insertAtEnd(head, 7);
    head = sol.insertAtEnd(head, 8);

    sol.print(head);
    Node *rev = sol.rotateRight(head, 2);
    sol.print(rev);
    Node *rev2 = sol.rotateLeft(rev, 2);
    sol.print(rev2);
}