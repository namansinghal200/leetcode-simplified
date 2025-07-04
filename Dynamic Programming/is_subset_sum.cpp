#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        // code here
        if (arr[0] == sum)
            return 1;

        int n = arr.size();
        vector<int> prev(sum + 1, 0), curr(sum + 1, 0);
        prev[0] = 1;
        if (arr[0] <= sum)
            prev[arr[0]] = 1;

        for (int i = 1; i < n; i++)
        {
            curr = prev;
            for (int j = 0; j + arr[i] <= sum; j++)
            {
                if (prev[j])
                    curr[j + arr[i]] = 1;
            }
            prev = curr;
        }
        return prev[sum];
    }
};
int main()
{
    int n, sum;
    cin >> n >> sum;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    Solution sol;
    cout << sol.isSubsetSum(v, sum) << endl;
}