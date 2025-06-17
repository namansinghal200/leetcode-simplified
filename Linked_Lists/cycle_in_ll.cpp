#include <bits/stdc++.h>
using namespace std;

// tortoise hare to find the cycle
// to find the length, run a while loop starting from slow->next
// to find the starting point, reset slow to head and find where slow==fast again
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

    bool hasCycle(Node *head)
    {
        if (!head)
            return false;
        Node *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }

    int findCycleLength(Node *head)
    {
        // cout << "in" << endl;
        Node *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                int count = 1;
                slow = slow->next;
                while (slow != fast)
                {
                    count++;
                    slow = slow->next;
                    // cout << "in3" << endl;
                }
                return count;
            }
        }
        return 0;
    }

    Node *findStartingPoint(Node *head)
    {
        Node *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
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
    Node *head = NULL;
    Solution sol;
    head = sol.insertAtEnd(head, 9);
    head = sol.insertAtEnd(head, 3);
    head = sol.insertAtEnd(head, 2);
    head = sol.insertAtEnd(head, 6);
    head->next->next->next->next = head->next;

    if (sol.hasCycle(head))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    cout << sol.findCycleLength(head) << endl;

    Node *start = sol.findStartingPoint(head);
    if (start == NULL)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << start->data << endl;
    }
}