#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLIS2(vector<int> &nums)
    {
        vector<int> lis(nums.size(), 1);
        int ans = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    lis[i] = max(lis[i], 1 + lis[j]);
                }
                ans = max(ans, lis[i]);
            }
        }
        return ans;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> lis;
        lis.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > lis.back())
            {
                lis.push_back(nums[i]);
            }
            else
            {
                int ind = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                lis[ind] = nums[i];
            }
        }
        // for (auto i: lis) cout<<i<<" ";
        return lis.size();
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> val(n);
    for (auto &i : val)
        cin >> i;
    Solution sol;
    cout << sol.lengthOfLIS(val) << endl;
    cout << sol.lengthOfLIS2(val) << endl;
}