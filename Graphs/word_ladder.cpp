// Problem Link: https://leetcode.com/problems/word-ladder/description/
// May look at Word-Ladder 2 as well as it is tougher.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<pair<string, int>> q;
        set<string> s(wordList.begin(), wordList.end());
        q.push({beginWord, 1});
        s.erase(beginWord);
        while (!q.empty())
        {
            string word = q.front().first;
            int moves = q.front().second;
            q.pop();
            if (word == endWord)
                return moves;
            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if (s.find(word) != s.end())
                    {
                        s.erase(word);
                        q.push({word, moves + 1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string beginWord, endWord;
        vector<string> wordList(n);
        cin >> beginWord >> endWord;
        for (auto &i : wordList)
            cin >> i;

        Solution sol;
        cout << sol.ladderLength(beginWord, endWord, wordList) << endl;
    }
}