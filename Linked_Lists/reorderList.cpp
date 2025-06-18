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

    Node *merge(Node *left, Node *right)
    {
        Node *dummy = new Node(-1);
        Node *temp = dummy;
        while (left || right)
        {
            if (left)
            {
                temp->next = left;
                left = left->next;
                temp = temp->next;
            }
            if (right)
            {
                temp->next = right;
                right = right->next;
                temp = temp->next;
            }
        }
        return dummy->next;
    }

    Node *reorderList(Node *head)
    {
        Node *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *newHead = reverse(slow->next);
        slow->next = NULL;

        return merge(head, newHead);
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
    // head = sol.insertAtEnd(head, 7);
    // head = sol.insertAtEnd(head, 8);

    sol.print(head);
    Node *rev = sol.reorderList(head);
    sol.print(rev);
}