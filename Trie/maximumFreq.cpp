// Problem Link: https://www.geeksforgeeks.org/problems/most-frequent-word-in-an-array-of-strings3528/1

#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    Trie *links[26];
    string str;
    int cnt;
    int ind;

    Trie()
    {
        for (int i = 0; i < 26; i++)
            links[i] = NULL;
        cnt = 0;
        str = "";
        ind = -1;
    }
};

class Solution
{
public:
    // Function to find most frequent word in an array of strings.
    int count = 0;
    string maxStr;
    int first = -1;
    Trie *root = new Trie();

    void insert(int pos, string &s)
    {
        Trie *temp = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (!temp->links[s[i] - 'a'])
                temp->links[s[i] - 'a'] = new Trie();
            temp = temp->links[s[i] - 'a'];
        }
        temp->str = s;
        temp->cnt++;
        if (temp->ind == -1)
            temp->ind = pos;
        if (temp->cnt > count || (temp->cnt == count && temp->ind > first))
        {
            count = temp->cnt;
            maxStr = temp->str;
            first = temp->ind;
        }
    }

    string mostFrequentWord(string arr[], int n)
    {
        // code here
        Solution sol;
        for (int i = 0; i < n; i++)
        {
            insert(i, arr[i]);
        }
        return maxStr;
    }
};

int main()
{
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Solution sol;
    string ans = sol.mostFrequentWord(arr, n);
    cout
        << ans << endl;
}