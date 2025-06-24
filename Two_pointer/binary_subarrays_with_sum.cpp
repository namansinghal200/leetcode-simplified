// Problem Link: https://leetcode.com/problems/binary-subarrays-with-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int goal)
    {
        int curr = 0;
        int ans = 0;
        int i = 0;
        if (goal < 0)
            return 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j])
                curr++;
            while (i < nums.size() && curr > goal)
            {
                if (nums[i])
                    curr--;
                i++;
            }
            ans += j - i + 1;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return solve(nums, goal) - solve(nums, goal - 1);
    }
};

int main()
{
    int n, goal;
    cin >> n >> goal;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    Solution sol;
    cout << sol.numSubarraysWithSum(v, goal) << endl;
}