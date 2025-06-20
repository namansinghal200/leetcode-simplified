// Problem Link: https://leetcode.com/problems/lfu-cache/description/
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    int value;
    int cnt;
    Node *next;
    Node *prev;

    Node(int key, int val)
    {
        this->key = key;
        this->value = val;

        // Initial frequency is 1
        cnt = 1;
    }
};

// LFU Cache class
class LFUCache
{
public:
    // Maps a key to the corresponding Node
    unordered_map<int, Node *> cacheMap;

    // Maps frequency to a pair of head and tail pointers
    unordered_map<int, pair<Node *, Node *>> freqMap;

    // Tracks the minimum frequency of the cache
    int minFreq;

    // Maximum capacity of the cache
    int capacity;

    // Constructor to initialize LFUCache with a given capacity
    LFUCache(int capacity)
    {
        this->capacity = capacity;

        // Initial minimum frequency is 0
        minFreq = 0;
    }

    // Function to get the value associated with a key
    int get(int key)
    {

        // Return -1 if key is not found in the cache
        if (cacheMap.find(key) == cacheMap.end())
        {
            return -1;
        }

        // Retrieve the Node and update its frequency
        Node *node = cacheMap[key];
        int res = node->value;
        updateFreq(node);
        return res;
    }

    // Function to add or update a key-value pair in the cache
    void put(int key, int value)
    {

        // Do nothing if the cache has zero capacity
        if (capacity == 0)
            return;

        // Update value if key already exists in the cache
        if (cacheMap.find(key) != cacheMap.end())
        {

            Node *node = cacheMap[key];
            node->value = value;
            updateFreq(node);
        }

        // Add a new key-value pair to the cache
        else
        {

            // Remove the least frequently used node if cache is full
            if (cacheMap.size() == capacity)
            {

                Node *node = freqMap[minFreq].second->prev;
                cacheMap.erase(node->key);
                remove(node);

                // Remove the frequency list if it's empty
                if (freqMap[minFreq].first->next == freqMap[minFreq].second)
                {
                    freqMap.erase(minFreq);
                }

                // Free memory
                delete node;
            }

            // Create a new node for the key-value pair
            Node *node = new Node(key, value);
            cacheMap[key] = node;

            // Reset minimum frequency to 1
            minFreq = 1;
            add(node, 1);
        }
    }

    // Add a node to the frequency list
    void add(Node *node, int freq)
    {

        // Initialize the frequency list if it doesn't exist
        if (freqMap.find(freq) == freqMap.end())
        {

            // Dummy head node
            Node *head = new Node(-1, -1);

            // Dummy tail node
            Node *tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            freqMap[freq] = {head, tail};
        }

        // Insert the node right after the head
        Node *head = freqMap[freq].first;
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }

    // Remove a node from the frequency list
    void remove(Node *node)
    {

        // Update pointers to exclude the node
        Node *delprev = node->prev;
        Node *delnext = node->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    // Update the frequency of a node
    void updateFreq(Node *node)
    {

        // Get the current frequency
        int oldFreq = node->cnt;

        // Increment the frequency
        node->cnt++;

        // Remove the node from the current frequency list
        remove(node);

        // Remove the frequency list if it becomes empty
        if (freqMap[oldFreq].first->next == freqMap[oldFreq].second)
        {
            freqMap.erase(oldFreq);

            // Update minimum frequency if needed
            if (minFreq == oldFreq)
            {
                minFreq++;
            }
        }

        // Add the node to the updated frequency list
        add(node, node->cnt);
    }
};
int main()
{
    int capacity;
    cin >> capacity;
    LFUCache lfu(capacity);
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
            lfu.put(x, y);
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            cout << lfu.get(x) << endl;
        }
    }
}