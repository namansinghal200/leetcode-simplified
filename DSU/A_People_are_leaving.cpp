#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> par, maxi;

    DSU(int n)
    {
        par.resize(n);
        maxi.resize(n);
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
            maxi[i] = i;
        }
    }

    int find(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]); // path compression
    }

    void unionn(int x, int y)
    {
        int parx = find(x);
        int pary = find(y);
        if (parx != pary)
        {
            par[parx] = pary;
            maxi[pary] = max(maxi[parx], maxi[pary]);
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        DSU ds(n + 2);
        for (int i = 0; i < m; i++)
        {
            string type;
            cin >> type;
            if (type == "?")
            {
                int x;
                cin >> x;
                int ans = ds.maxi[ds.find(x)];
                cout << ((ans == n + 1) ? -1 : ans) << '\n'; // use '\n' instead of endl
            }
            else
            {
                int x;
                cin >> x;
                ds.unionn(x, x + 1);
            }
        }
    }
    return 0;
}
