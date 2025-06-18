#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[2];
};
class Solution
{
public:
    Node *root = new Node();
    void insert(int num)
    {
        bitset<32> b(num);
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            if (node->links[b[i]] == NULL)
                node->links[b[i]] = new Node();
            node = node->links[b[i]];
        }
    }
    int search(int num)
    {
        bitset<32> b(num);
        Node *node = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            if (node->links[b[i] ^ 1])
            {
                ans += (1 << i);
                node = node->links[b[i] ^ 1];
            }
            else
            {
                node = node->links[b[i]];
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int> &nums)
    {
        for (auto i : nums)
        {
            insert(i);
        }
        int ans = 0;
        for (auto i : nums)
        {
            int num = search(i);
            ans = max(ans, num);
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution sol;
    cout << sol.findMaximumXOR(nums) << endl;
}