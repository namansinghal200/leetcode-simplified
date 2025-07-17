#include <bits/stdc++.h>
using namespace std;
#define int long long int

int timer = 1;
vector<int> in, out, vec;
void dfs(int node, int par, vector<vector<int>> &adj, vector<int> &values)
{
    in[node] = timer;
    vec[timer] = values[node];
    timer++;
    for (auto i : adj[node])
    {
        if (i != par)
        {
            dfs(i, node, adj, values);
        }
    }
    out[node] = timer;
}

class Segtree
{
    vector<int> seg;

public:
    Segtree(int n)
    {
        seg.resize(4 * n + 1);
    }
    int update(int ind, int tl, int tr, int x, int y)
    {
        if (tl == tr)
        {
            return seg[ind] = y;
        }
        int mid = (tl + tr) / 2;
        if (x <= mid)
            update(2 * ind, tl, mid, x, y);
        else
            update(2 * ind + 1, mid + 1, tr, x, y);
        return seg[ind] = seg[2 * ind] + seg[2 * ind + 1];
    }
    int query(int ind, int tl, int tr, int l, int r)
    {
        if (l > r)
            return 0;
        if (tl == l && r == tr)
            return seg[ind];
        int mid = (tl + tr) / 2;
        int lsum = query(2 * ind, tl, mid, l, min(mid, r));
        int rsum = query(2 * ind + 1, mid + 1, tr, max(l, mid + 1), r);
        return lsum + rsum;
    }
    void print()
    {
        for (auto i : seg)
            cout << i << " ";
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> values(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> values[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    in.resize(n + 1);
    out.resize(n + 1);
    vec.resize(n + 1);

    dfs(1, -1, adj, values);
    // for (int i = 0; i < in.size(); i++)
    // {
    //     cout << in[i] << " " << vec[i] << " " << out[i] << endl;
    // }
    Segtree st(n + 1);
    for (int i = 1; i < vec.size(); i++)
    {
        st.update(1, 0, n, i, vec[i]);
    }
    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, y;
            cin >> x >> y;
            vec[in[x]] = y;
            st.update(1, 0, n, in[x], y);
        }
        else
        {
            int x;
            cin >> x;
            cout << st.query(1, 0, n, in[x], out[x] - 1) << endl;
        }
    }
}
#undef int
int main()
{
    solve();
}