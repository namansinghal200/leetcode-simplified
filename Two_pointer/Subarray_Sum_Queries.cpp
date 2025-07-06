#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define all(x) (x).begin(), (x).end()
#define mod 1000000007

struct item
{
    int seg, pref, suff, sum;
};
struct segtree
{

    vector<item> seg;
    void init(int n)
    {
        seg.resize(4 * n + 1);
    }

    item single(int x)
    {
        if (x > 0)
            return {x, x, x, x};
        else
            return {0, 0, 0, x};
    }
    item merge(item a, item b)
    {
        return {max({a.seg, b.seg, a.suff + b.pref}), max(a.pref, a.sum + b.pref), max(b.suff, b.sum + a.suff), a.sum + b.sum};
    }
    // item build(int v, int tl, int tr, vector<int> &a)
    // {
    //     if (tl == tr)
    //         return seg[v] = {a[tl], 1};
    //     int tm = (tl + tr) / 2;
    //     build(2 * v, tl, tm, a);
    //     build(2 * v + 1, tm + 1, tr, a);
    //     return seg[v] = merge(seg[2 * v], seg[2 * v + 1]);
    // }
    item update(int v, int tl, int tr, int x, int y)
    {
        if (tl == tr)
            return seg[v] = single(y);
        int tm = (tl + tr) / 2;
        if (x <= tm)
            update(2 * v, tl, tm, x, y);
        else
            update(2 * v + 1, tm + 1, tr, x, y);

        return seg[v] = merge(seg[2 * v], seg[2 * v + 1]);
    }
    item query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return {0, 0, 0, 0};
        if (tl == l && tr == r)
            return seg[v];
        int tm = (tl + tr) / 2;

        return merge(query(2 * v, tl, tm, l, min(tm, r)), query(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);

    segtree st;
    st.init(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.update(1, 0, n - 1, i, x);
    }
    // st.build(1, 0, n - 1, a);
    // cout << st.query(1, 0, n - 1, 0, n - 1).seg << endl;
    for (int i = 0; i < q; i++)
    {
        // for (auto j : st.seg)
        //     cout << "(" << j.m << ", " << j.c << ")" << " ";
        // cout << endl;
        int x, y;
        cin >> x >> y;
        st.update(1, 0, n - 1, x - 1, y);
        item ans = st.query(1, 0, n - 1, 0, n - 1);
        cout << ans.seg << endl;
    }
}
#undef int
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
