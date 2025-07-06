#include <bits/stdc++.h>
using namespace std;
#define int long long int

class Segtree
{
    vector<int> seg;

public:
    Segtree(int n)
    {
        seg.resize(4 * n + 1, LLONG_MAX);
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
        return seg[v] = min(seg[2 * v + 1], seg[2 * v]);
    }
    int query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return LLONG_MAX;
        if (tl == l && tr == r)
            return seg[v];
        int tm = (tl + tr) / 2;

        return min(query(2 * v, tl, tm, l, min(tm, r)), query(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
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
    Segtree t1(n + 1), t2(n + 1);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        t1.update(1, 0, n - 1, i, x + i);
        t2.update(1, 0, n - 1, i, x - i);
    }
    // t1.print();
    // t2.print();
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, y;
            cin >> x >> y;
            x--;
            t1.update(1, 0, n - 1, x, y + x);
            t2.update(1, 0, n - 1, x, y - x);
        }
        else
        {
            int k;
            cin >> k;
            k--;
            cout << min(t2.query(1, 0, n - 1, 0, k) + k, t1.query(1, 0, n - 1, k, n - 1) - k) << endl;
        }
    }
}
#undef int
int main()
{
    solve();
}