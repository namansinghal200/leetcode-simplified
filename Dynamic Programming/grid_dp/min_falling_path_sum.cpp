// Problem Link: https://leetcode.com/problems/unique-paths/
// Problem Link: https://leetcode.com/problems/unique-paths-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();

        vector<int> prev = matrix[0], curr(m);
        for (int i = 1; i < n; i++)
        {
            curr = matrix[i];
            for (int j = 0; j < m; j++)
            {
                int num = prev[j];
                if (j > 0)
                    num = min(num, prev[j - 1]);
                if (j < n - 1)
                    num = min(num, prev[j + 1]);
                curr[j] += num;
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    Solution sol;
    cout << sol.minFallingPathSum(mat) << endl;
}