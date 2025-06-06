#include <bits/stdc++.h>
using namespace std;
class DSU
{

public:
    vector<int> par, extra, score, size;
    DSU(int n)
    {
        par.resize(n);
        extra.resize(n);
        score.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
            size[i] = 1;
        }
    }
    int find(int x)
    {
        if (par[x] == x)
            return x;
        return find(par[x]);
    }

    void unionByExp(int x, int y)
    {
        int parx = find(x);
        int pary = find(y);
        if (parx != pary)
        {
            if (size[parx] < size[pary])
                swap(parx, pary);
            par[pary] = parx;
            size[parx] += size[pary];
            extra[pary] = score[parx];
        }
    }

    int get_score(int x)
    {
        if (par[x] == x)
            return score[x];
        return score[x] - extra[x] + get_score(par[x]);
    }

    void update(int x, int y)
    {
        int parx = find(x);
        score[parx] += y;
    }
};

int main()
{
    int t = 1;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        DSU ds(n + 1);
        for (int i = 0; i < m; i++)
        {
            string type;
            cin >> type;
            if (type == "get")
            {
                int x;
                cin >> x;
                int par = ds.find(x);
                cout << ds.get_score(x) << endl;
            }
            else if (type == "add")
            {
                int x, v;
                cin >> x >> v;
                ds.update(x, v);
            }
            else
            {
                int x, y;
                cin >> x >> y;
                ds.unionByExp(x, y);
            }
        }
    }
}