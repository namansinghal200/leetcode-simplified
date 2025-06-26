// Problem Link: https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/B
#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve()
{
    int n, s;
    cin >> n >> s;
    vector<int> v1(n);
    for (auto &i : v1)
        cin >> i;

    int i = 0, ans = n + 1, sum = 0;
    for (int j = 0; j < n; j++)
    {
        sum += v1[j];
        while (i < n && (sum - v1[i]) >= s)
        {
            sum -= v1[i];
            i++;
        }
        // cout << sum << " " << i << " " << j << endl;
        if (sum >= s)
            ans = min(ans, j - i + 1);
    }
    cout << ((ans == n + 1) ? -1 : ans) << endl;
}

#undef int
int main()
{
    solve();
}