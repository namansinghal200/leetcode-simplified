// Problem Link: https://leetcode.com/problems/lru-cache/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    int data;
    Node *prev, *next;
    Node(int k, int d)
    {
        key = k;
        data = d;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache
{
public:
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    unordered_map<int, Node *> m;
    int cap;

    void addNode(int key, int data)
    {
        Node *temp = head->next;
        Node *newNode = new Node(key, data);
        head->next = newNode;
        newNode->next = temp;
        temp->prev = newNode;
        newNode->prev = head;
    }

    void delNode(Node *node)
    {
        Node *prev = node->prev, *next = node->next;
        prev->next = next;
        next->prev = prev;
        delete (node);
    }

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        int ans = -1;
        if (m.find(key) != m.end())
        {
            Node *node = m[key];
            ans = node->data;
            addNode(key, node->data);
            m[key] = head->next;
            delNode(node);
        }
        return ans;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            Node *node = m[key];
            delNode(node);
            m.erase(key);
        }
        if (m.size() == cap)
        {
            Node *node = tail->prev;
            m.erase(node->key);
            delNode(node);
        }
        addNode(key, value);
        m[key] = head->next;
    }
};

int main()
{
    int capacity;
    cin >> capacity;
    LRUCache lru(capacity);
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, y;
            cin >> x >> y;
            lru.put(x, y);
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            cout << lru.get(x) << endl;
        }
    }
}