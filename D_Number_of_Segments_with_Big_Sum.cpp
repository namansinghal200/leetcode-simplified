// Problem Link: https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/D
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

    int i = 0, ans = 0, sum = 0;
    for (int j = 0; j < n; j++)
    {
        sum += v1[j];
        while (i < n && sum >= s)
        {
            ans += n - j;
            sum -= v1[i];
            i++;
        }
    }
    cout << ans << endl;
}

#undef int
int main()
{
    solve();
}