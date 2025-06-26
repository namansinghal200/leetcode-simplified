// Problem Link: https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/E
#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve()
{
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;

    map<int, int> m;
    int count = 0, i = 0;
    for (int j = 0; j < n; j++)
    {
        m[v[j]]++;
        while (i < n && m.size() > s)
        {
            m[v[i]]--;
            if (m[v[i]] == 0)
                m.erase(v[i]);
            i++;
        }
        count += j - i + 1;
    }
    cout << count << endl;
}

#undef int
int main()
{
    solve();
}