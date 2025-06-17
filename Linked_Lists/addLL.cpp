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

    Node *addLL(Node *head1, Node *head2)
    {
        Node *l1 = reverse(head1), *l2 = reverse(head2);
        Node *dummy = new Node(-1);
        Node *temp = dummy;

        int carry = 0;
        while (l1 && l2)
        {
            int sum = l1->data + l2->data + carry;
            temp->next = new Node(sum % 10);
            carry = sum / 10;
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            int sum = l1->data + carry;
            temp->next = new Node(sum % 10);
            carry = sum / 10;
            temp = temp->next;
            l1 = l1->next;
        }
        while (l2)
        {
            int sum = l2->data + carry;
            temp->next = new Node(sum % 10);
            carry = sum / 10;
            temp = temp->next;
            l2 = l2->next;
        }
        return reverse(dummy->next);
    }
};

int main()
{
    Node *head = NULL, *head2 = NULL;
    Solution sol;
    head = sol.insertAtEnd(head, 9);
    head = sol.insertAtEnd(head, 3);
    head = sol.insertAtEnd(head, 2);
    head = sol.insertAtEnd(head, 6);
    head = sol.insertAtEnd(head, 7);
    head = sol.insertAtEnd(head, 8);

    head2 = sol.insertAtEnd(head2, 9);
    head2 = sol.insertAtEnd(head2, 3);
    head2 = sol.insertAtEnd(head2, 2);

    Node *head3 = sol.addLL(head, head2);
    sol.print(head3);
}