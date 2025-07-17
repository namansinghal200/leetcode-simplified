#include <bits/stdc++.h>
using namespace std;

#define int long long

int timer = 0;
vector<int> in, out, v;
vector<vector<int>> adj;

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
        for (auto i : add)
            cout << i << " ";
        cout << endl;
    }
};

void dfs(int u, int parent = 0)
{
    in[u] = ++timer;
    for (int to : adj[u])
    {
        if (to != parent)
            dfs(to, u);
    }
    out[u] = timer;
}

void solve()
{
    int N, Q;
    cin >> N >> Q;

    v.resize(N + 1);
    adj.resize(N + 1);
    in.resize(N + 1);
    out.resize(N + 1);

    for (int i = 1; i <= N; i++)
        cin >> v[i];

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    Segtree st(N + 2);
    // for (int i = 1; i <= N; i++)
    // {
    //     cout << in[i] << " " << out[i] << " " << flatTree[i] << endl;
    // }
    for (int i = 1; i <= N; i++)
    {
        st.updateQ(1, 0, N, in[i], out[i], v[i]);
    }
    // st.print();

    while (Q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int ind, newVal;
            cin >> ind >> newVal;
            st.updateQ(1, 0, N, in[ind], out[ind], newVal - v[ind]);
            v[ind] = newVal;
        }
        else if (type == 2)
        {
            int ind;
            cin >> ind;
            cout << st.query(1, 0, N, in[ind]) << "\n";
        }
    }
}

#undef int
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
