#include <bits/stdc++.h>
using namespace std;

class Stack
{
    queue<int> q;

public:
    void push(int x)
    {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    void pop()
    {
        if (!q.size())
            return;
        q.pop();
    }
    int top()
    {
        if (!q.size())
            return -1;
        return q.front();
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
        else
        {
            cout << st.top() << endl;
        }
    }
}