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

    Node *reverseEvenNodes(Node *head)
    {
        Node *odd = head, *even = NULL;

        if (!odd || !odd->next || !odd->next->next)
            return odd;
        while (odd && odd->next)
        {
            Node *temp = odd->next;
            odd->next = temp->next;

            temp->next = even;
            even = temp;

            odd = odd->next;
        }

        odd = head;
        while (even)
        {
            Node *temp = even->next;
            even->next = odd->next;
            odd->next = even;
            even = temp;
            odd = odd->next->next;
        }
        return head;
    }

    Node *reverseEvenandAppend(Node *head)
    {
        if (!head || !head->next)
            return head;
        Node *odd = head, *even = NULL;
        Node *prev = NULL, *temp = odd;

        while (temp && temp->next)
        {
            Node *nextt = temp->next;
            prev = temp;
            temp->next = nextt->next;
            nextt->next = even;
            even = nextt;
            temp = temp->next;
        }
        if (temp)
        {
            prev = temp;
        }
        prev->next = even;
        return odd;
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
    head = sol.insertAtEnd(head, 2);
    // head = sol.insertAtEnd(head, 1);

    sol.print(head);
    auto rev = sol.reverseEvenNodes(head);
    sol.print(rev);
    auto rev2 = sol.reverseEvenandAppend(rev);
    sol.print(rev2);
}