#include <bits/stdc++.h>
using namespace std;

class Queue
{
    stack<int> enqueue, dequeue;

public:
    void push(int x)
    {
        enqueue.push(x);
    }
    void pop()
    {
        if (dequeue.empty() && enqueue.empty())
            return;
        if (!dequeue.empty())
        {
            dequeue.pop();
            return;
        }
        while (!enqueue.empty())
        {
            dequeue.push(enqueue.top());
            enqueue.pop();
        }
        dequeue.pop();
    }
    int front()
    {
        if (dequeue.empty() && enqueue.empty())
            return -1;
        if (!dequeue.empty())
        {
            return dequeue.top();
        }
        while (!enqueue.empty())
        {
            dequeue.push(enqueue.top());
            enqueue.pop();
        }
        return dequeue.top();
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