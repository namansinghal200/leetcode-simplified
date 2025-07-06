#include <bits/stdc++.h>
using namespace std;
#define int long long int

class Segtree
{
    vector<int> seg, add;

public:
    Segtree(int n)
    {
        seg.resize(4 * n + 1);
        add.resize(4 * n + 1);
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
        return seg[v] = seg[2 * v + 1] + seg[2 * v];
    }
    int updateQ(int v, int tl, int tr, int l, int r, int val)
    {
        if (l > r)
            return 0;
        if (tl == l && tr == r)
            return add[v] += val;
        int tm = (tl + tr) / 2;

        updateQ(2 * v, tl, tm, l, min(tm, r), val);
        updateQ(2 * v + 1, tm + 1, tr, max(tm + 1, l), r, val);
        return 0;
    }
    int query(int v, int tl, int tr, int x)
    {
        if (tl == tr)
            return add[v] + seg[v];
        int tm = (tl + tr) / 2;
        if (x <= tm)
            return add[v] + query(2 * v, tl, tm, x);
        return add[v] + query(2 * v + 1, tm + 1, tr, x);
    }
    void print()
    {
        for (auto i : seg)
            cout << i << " ";
        cout << endl;
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
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, y, val;
            cin >> x >> y >> val;
            seg.updateQ(1, 0, n - 1, x - 1, y - 1, val);
        }
        else
        {
            int x;
            cin >> x;
            cout << seg.query(1, 0, n - 1, x - 1) << endl;
        }
    }
}
#undef int
int main()
{
    solve();
}