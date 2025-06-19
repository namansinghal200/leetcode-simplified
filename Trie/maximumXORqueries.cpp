// Problem Link:
#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    Trie *links[2];
    bool end = 0;
    Trie()
    {
        for (int i = 0; i < 2; i++)
            links[i] = NULL;
        end = false;
    }
};
class Solution
{
public:
    Trie *root = new Trie();

    void insert(int x)
    {
        Trie *temp = root;

        bitset<32> v(x);
        for (int i = 31; i >= 0; i--)
        {
            if (!temp->links[v[i]])
                temp->links[v[i]] = new Trie();
            temp = temp->links[v[i]];
        }
        temp->end = true;
    }

    int getMax(int x)
    {
        bitset<32> v(x);
        Trie *temp = root;
        int maxi = 0;

        for (int i = 31; i >= 0; i--)
        {
            if (temp->links[v[i] ^ 1])
            {
                maxi += (1 << i);
                temp = temp->links[v[i] ^ 1];
            }
            else
                temp = temp->links[v[i]];
        }
        return maxi;
    }
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> q;
        vector<int> ans(queries.size());

        for (int i = 0; i < queries.size(); i++)
        {
            q.push_back({queries[i][1], queries[i][0], i});
        }

        sort(q.begin(), q.end());

        int i = 0, n = nums.size();
        for (int j = 0; j < q.size(); j++)
        {
            while (i < n && nums[i] <= q[j][0])
            {
                insert(nums[i]);
                i++;
            }
            if (i == 0)
                ans[q[j][2]] = -1;
            else
                ans[q[j][2]] = getMax(q[j][1]);
        }

        return ans;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<vector<int>> queries(m, vector<int>(2, 0));
    for (int i = 0; i < queries.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> queries[i][j];
        }
    }

    Solution sol;
    auto ans = sol.maximizeXor(nums, queries);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}