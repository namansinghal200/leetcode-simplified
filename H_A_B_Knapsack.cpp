// Problem Link: https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve()
{
    int n, m, s, a, b;
    cin >> n >> m >> s >> a >> b;
    vector<int> v1(n), v2(m);
    for (auto &i : v1)
        cin >> i;
    for (auto &i : v2)
        cin >> i;

    sort(v1.begin(), v1.end(), greater<int>());
    sort(v2.begin(), v2.end(), greater<int>());

    int bc = min(m, s / b), curr_w = bc * b, curr_c = 0;
    for (int i = 0; i < bc; i++)
        curr_c += v2[i];

    int ans = curr_c;
    for (int ac = 1; ac <= v1.size(); ac++)
    {
        curr_w += a;
        curr_c += v1[ac - 1];
        while (bc > 0 && curr_w > s)
        {
            curr_c -= v2[bc - 1];
            curr_w -= b;
            bc--;
        }
        if (curr_w > s)
            break;
        ans = max(ans, curr_c);
        // cout << ac << " " << bc << " " << curr_c << endl;
    }
    cout << ans << endl;
}

#undef int
int main()
{
    solve();
}