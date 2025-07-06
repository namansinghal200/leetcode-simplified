#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node
{
    int sum, prefix;
    Node(int val = 0)
    {
        sum = val;
        prefix = max(0LL, val);
    }
};

struct SegTree
{
    int n;
    vector<Node> tree;

    SegTree(int n)
    {
        tree.resize(4 * n);
    }

    Node merge(Node a, Node b)
    {
        Node res;
        res.sum = a.sum + b.sum;
        res.prefix = max(a.prefix, a.sum + b.prefix);
        return res;
    }

    void update(int v, int tl, int tr, int pos, int new_val)
    {
        if (tl == tr)
        {
            tree[v] = Node(new_val);
            return;
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(2 * v, tl, tm, pos, new_val);
        else
            update(2 * v + 1, tm + 1, tr, pos, new_val);
        tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
    }

    Node query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return Node(0); // identity for prefix sum
        if (l == tl && r == tr)
            return tree[v];
        int tm = (tl + tr) / 2;
        Node left = query(2 * v, tl, tm, l, min(r, tm));
        Node right = query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
        return merge(left, right);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    SegTree seg(n + 1);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        seg.update(1, 0, n - 1, i, x);
    }
    // seg.print();
    for (int i = 0; i < q; i++)
    {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1)
        {
            seg.update(1, 0, n - 1, x - 1, y);
        }
        else
        {
            cout << seg.query(1, 0, n - 1, x - 1, y - 1).prefix << endl;
        }
    }
}
#undef int
int main()
{
    solve();
}