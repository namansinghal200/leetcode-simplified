#include <bits/stdc++.h>
using namespace std;
class DSU
{

public:
    vector<int> par, rank, size, mini, maxi;
    DSU(int n)
    {
        par.resize(n);
        rank.resize(n);
        size.resize(n);
        maxi.resize(n);
        mini.resize(n);
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
            rank[i] = 1;
            size[i] = 1;
            mini[i] = i;
            maxi[i] = i;
        }
    }
    int find(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }
    void unionByRank(int x, int y)
    {
        int parx = find(x);
        int pary = find(y);
        if (parx != pary)
        {
            if (rank[parx] > rank[pary])
                par[pary] = parx;
            else if (rank[parx] < rank[pary])
                par[parx] = pary;
            else
                par[pary] = parx, rank[parx]++;
        }
    }

    void unionBySize(int x, int y)
    {
        int parx = find(x);
        int pary = find(y);
        if (parx != pary)
        {
            if (size[parx] < size[pary])
            {
                par[parx] = pary;
                size[pary] += size[parx];
                mini[pary] = min(mini[parx], mini[pary]);
                maxi[pary] = max(maxi[parx], maxi[pary]);
            }
            else
            {
                par[pary] = parx;
                size[parx] += size[pary];
                mini[parx] = min(mini[parx], mini[pary]);
                maxi[parx] = max(maxi[parx], maxi[pary]);
            }
        }
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
                cout << ds.mini[par] << " " << ds.maxi[par] << " " << ds.size[par] << endl;
            }
            else
            {
                int x, y;
                cin >> x >> y;
                ds.unionBySize(x, y);
            }
        }
    }
}