#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

struct Node
{
    int sum = 0;
    int add = 0;
    int assign = -1; // -1 means no assignment pending
};

class SegmentTree
{
public:
    vector<Node> tree;
    int n;

    SegmentTree(int size)
    {
        n = size;
        tree.resize(4 * n);
    }

    void build(vector<int> &arr, int v = 1, int tl = 0, int tr = -1)
    {
        if (tr == -1)
            tr = n - 1;
        if (tl == tr)
        {
            tree[v].sum = arr[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(arr, v * 2, tl, tm);
        build(arr, v * 2 + 1, tm + 1, tr);
        tree[v].sum = tree[v * 2].sum + tree[v * 2 + 1].sum;
    }

    void push(int v, int tl, int tr)
    {
        if (tree[v].assign != -1)
        {
            int val = tree[v].assign;
            tree[v].sum = val * (tr - tl + 1);
            if (tl != tr)
            {
                apply_assign(v * 2, val);
                apply_assign(v * 2 + 1, val);
            }
            tree[v].assign = -1;
            tree[v].add = 0;
        }
        else if (tree[v].add != 0)
        {
            tree[v].sum += tree[v].add * (tr - tl + 1);
            if (tl != tr)
            {
                apply_add(v * 2, tree[v].add);
                apply_add(v * 2 + 1, tree[v].add);
            }
            tree[v].add = 0;
        }
    }

    void apply_add(int v, int val)
    {
        if (tree[v].assign != -1)
        {
            tree[v].assign += val;
        }
        else
        {
            tree[v].add += val;
        }
    }

    void apply_assign(int v, int val)
    {
        tree[v].assign = val;
        tree[v].add = 0;
    }

    void range_add(int l, int r, int val, int v = 1, int tl = 0, int tr = -1)
    {
        if (tr == -1)
            tr = n - 1;
        push(v, tl, tr);
        if (l > r)
            return;
        if (tl == l && tr == r)
        {
            apply_add(v, val);
            push(v, tl, tr);
            return;
        }
        int tm = (tl + tr) / 2;
        range_add(l, min(r, tm), val, v * 2, tl, tm);
        range_add(max(l, tm + 1), r, val, v * 2 + 1, tm + 1, tr);
        tree[v].sum = tree[v * 2].sum + tree[v * 2 + 1].sum;
    }

    void range_set(int l, int r, int val, int v = 1, int tl = 0, int tr = -1)
    {
        if (tr == -1)
            tr = n - 1;
        push(v, tl, tr);
        if (l > r)
            return;
        if (tl == l && tr == r)
        {
            apply_assign(v, val);
            push(v, tl, tr);
            return;
        }
        int tm = (tl + tr) / 2;
        range_set(l, min(r, tm), val, v * 2, tl, tm);
        range_set(max(l, tm + 1), r, val, v * 2 + 1, tm + 1, tr);
        tree[v].sum = tree[v * 2].sum + tree[v * 2 + 1].sum;
    }

    int range_sum(int l, int r, int v = 1, int tl = 0, int tr = -1)
    {
        if (tr == -1)
            tr = n - 1;
        push(v, tl, tr);
        if (l > r)
            return 0;
        if (tl == l && tr == r)
            return tree[v].sum;
        int tm = (tl + tr) / 2;
        return range_sum(l, min(r, tm), v * 2, tl, tm) + range_sum(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    SegmentTree st(n);
    st.build(a);

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            st.range_add(l - 1, r - 1, x);
        }
        else if (type == 2)
        {
            int l, r, x;
            cin >> l >> r >> x;
            st.range_set(l - 1, r - 1, x);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << st.range_sum(l - 1, r - 1) << '\n';
        }
    }
}

#undef int
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
