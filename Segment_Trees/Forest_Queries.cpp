#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<string> v(n);
    for (auto &i : v)
        cin >> i;
    vector<vector<int>> tree(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        tree[i][1] = tree[i - 1][1] + (v[i - 1][0] == '*');
        tree[1][i] = tree[1][i - 1] + (v[0][i - 1] == '*');
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            tree[i][j] = tree[i - 1][j] + tree[i][j - 1] - tree[i - 1][j - 1] + (v[i - 1][j - 1] == '*');
        }
    }
    // for (auto i : tree)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < q; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << tree[x2][y2] - tree[x1 - 1][y2] - tree[x2][y1 - 1] + tree[x1 - 1][y1 - 1] << endl;
    }
}