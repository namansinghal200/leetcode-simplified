#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    Trie *child[26];
    bool end;
    int count;
    int countPref;
    Trie()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
        end = false;
        count = 0;
        countPref = 0;
    }
    void putKey(int x, Trie *node)
    {
        child[x] = node;
    }
    bool containKey(int x)
    {
        return (child[x] != NULL);
    }
    Trie *getKey(int x)
    {
        return child[x];
    }
    void setEnd()
    {
        end = true;
    }
    bool isEnd()
    {
        return end;
    }
    void changePrefCount(int x)
    {
        countPref += x;
    }
    void changeCount(int x)
    {
        count += x;
    }
    int getPrefCount()
    {
        return countPref;
    }
    int getCount()
    {
        return count;
    }
};

class Solution
{
    Trie *root;

public:
    Solution()
    {
        root = new Trie();
    }

    void insert(string s)
    {
        Trie *temp = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (!temp->containKey(s[i] - 'a'))
            {
                temp->putKey(s[i] - 'a', new Trie());
            }
            temp = temp->getKey(s[i] - 'a');
            temp->changePrefCount(1); // not necessary in standard trie
        }
        temp->setEnd();
        temp->changeCount(1); // not necessary in standard trie
    }

    bool search(string s)
    {
        Trie *temp = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (!temp->containKey(s[i] - 'a'))
                return false;
            temp = temp->getKey(s[i] - 'a');
        }
        return temp->isEnd();
    }

    bool startsWith(string s)
    {
        Trie *temp = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (!temp->containKey(s[i] - 'a'))
                return false;
            temp = temp->getKey(s[i] - 'a');
        }
        return true;
    }

    int countWordsWithPrefix(string s)
    {
        Trie *temp = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (!temp->containKey(s[i] - 'a'))
                return 0;
            temp = temp->getKey(s[i] - 'a');
        }
        return temp->getPrefCount();
    }

    int countWords(string s)
    {
        Trie *temp = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (!temp->containKey(s[i] - 'a'))
                return 0;
            temp = temp->getKey(s[i] - 'a');
        }
        return temp->getCount();
    }

    void erase(string s)
    {
        Trie *temp = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (!temp->containKey(s[i] - 'a'))
                return;
            temp = temp->getKey(s[i] - 'a');
            temp->changePrefCount(-1);
        }
        temp->changeCount(-1);
    }

    void print(Trie *root, string current)
    {
        if (!root)
            return;

        if (root->isEnd())
            cout << current << endl;

        for (int i = 0; i < 26; i++)
        {
            if (root->containKey(i))
            {
                char ch = 'a' + i;
                print(root->getKey(i), current + ch);
            }
        }
    }
    void printTrie()
    {
        print(root, "");
    }
};
int main()
{
    int n;
    cin >> n;

    Solution sol;
    for (int i = 0; i < n; i++)
    {
        int s;
        string s2;
        cin >> s >> s2;
        if (s == 1)
        {
            sol.insert(s2);
        }
        else if (s == 2)
        {
            bool find = sol.search(s2);
            cout << ((find == 1) ? "YES" : "NO") << endl;
        }
        else if (s == 3)
        {
            bool find = sol.startsWith(s2);
            cout << ((find == 1) ? "YES" : "NO") << endl;
        }
        else if (s == 4)
        {
            cout << sol.countWordsWithPrefix(s2) << endl;
        }
        else if (s == 5)
        {
            cout << sol.countWords(s2) << endl;
        }
        else
        {
            sol.erase(s2);
        }
    }
    // sol.printTrie();
}