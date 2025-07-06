#include <bits/stdc++.h>
using namespace std;
#define int long long int

class Segtree
{
    vector<int> seg;

public:
    Segtree(int n)
    {
        seg.resize(4 * n + 1);
    }
    int update(int v, int tl, int tr, int x, int y)
    {
        if (tl == tr)
            return seg[v] = y;
        int tm = (tl + tr) / 2;
        if (x <= tm)
            update(2 * v, tl, tm, x, y);
        else
            update(2 * v + 1, tm + 1, tr, x, y);
        return seg[v] = max(seg[2 * v + 1], seg[2 * v]);
    }
    pair<int, int> query(int v, int tl, int tr, int x)
    {
        // cout << v << " " << seg[v] << " " << x << " " << tl << " " << tr << endl;
        if (seg[v] < x)
            return {-1, -1};
        if (tl == tr)
            return {seg[v], tl};
        int tm = (tl + tr) / 2;

        pair<int, int> ans = query(2 * v, tl, tm, x);
        if (ans.first != -1)
            return ans;
        return query(2 * v + 1, tm + 1, tr, x);
    }
    void print()
    {
        for (auto i : seg)
            cout << i << " ";
        cout << endl;
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    Segtree seg(n + 1);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        seg.update(1, 0, n - 1, i, x);
    }
    // seg.print();
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        pair<int, int> v = seg.query(1, 0, n - 1, x);
        // cout << v.first << " " << v.second << endl;
        if (v.first == -1)
            cout << 0 << " ";
        else
        {
            cout << v.second + 1 << " ";
            // cout << v.first << " " << v.second << endl;
            seg.update(1, 0, n - 1, v.second, v.first - x);
            // seg.print();
        }
    }
}
#undef int
int main()
{
    solve();
}