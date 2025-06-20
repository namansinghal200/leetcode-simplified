// Problem Link: https://www.geeksforgeeks.org/problems/implement-queue-using-linked-list/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *next;
    int data;
    Node(int x)
    {
        next = NULL;
        data = x;
    }
};

class Queue
{
    Node *frontt = NULL, *rear = NULL;

public:
    void push(int x)
    {
        Node *newNode = new Node(x);
        if (!frontt)
        {
            frontt = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = rear->next;
        }
    }
    void pop()
    {
        if (!frontt)
            return;
        Node *temp = frontt;
        frontt = frontt->next;
        delete (temp);
    }
    int front()
    {
        if (!frontt)
            return -1;
        return frontt->data;
    }
};

int main()
{
    int queries;
    cin >> queries;
    Queue q;
    for (int i = 0; i < queries; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int y;
            cin >> y;
            q.push(y);
        }
        else if (x == 2)
        {
            q.pop();
        }
        else
        {
            cout << q.front() << endl;
        }
    }
}