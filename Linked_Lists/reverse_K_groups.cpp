#include <bits/stdc++.h>
using namespace std;

// just reversing like earlier but maintaining a counter of K
// It's essential to understand that if there are more than K nodes, we link the head pointer (tail of our reversed ll) to the recursively obtained reversed list of the remaining nodes.
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

    Node *reverseK(Node *head, int k)
    {
        if (head == NULL)
            return head;

        int count = 0;
        Node *prev = NULL, *nextt = NULL, *curr = head;
        while (curr && count < k)
        {
            nextt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextt;
            count++;
        }

        if (nextt)
        {
            head->next = reverseK(nextt, k);
        }
        return prev;
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
    Node *rev = sol.reverseK(head, 4);
    sol.print(rev);
}