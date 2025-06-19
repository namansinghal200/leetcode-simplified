// Problem Link: https://www.geeksforgeeks.org/problems/implement-stack-using-linked-list/1

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

class Stack
{
    Node *head = NULL;

public:
    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
    }
    void pop()
    {
        if (!head)
            return;
        Node *temp = head;
        head = head->next;
        delete (temp);
    }
    int top()
    {
        if (!head)
            return -1;
        return head->data;
    }
};

int main()
{
    int queries;
    cin >> queries;
    Stack st;
    for (int i = 0; i < queries; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int y;
            cin >> y;
            st.push(y);
        }
        else if (x == 2)
        {
            st.pop();
        }
        else if (x == 3)
        {
            cout << st.top() << endl;
        }
    }
}