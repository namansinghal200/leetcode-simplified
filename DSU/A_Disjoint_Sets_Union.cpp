// Problem Link: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/A
// itmo dsu step1, q1 (link not working)
#include <bits/stdc++.h>
using namespace std;
class DSU
{

public:
    vector<int> par, rank, size;
    DSU(int n)
    {
        par.resize(n);
        rank.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
            rank[i] = 1;
            size[i] = 1;
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
            }
            else
            {
                par[pary] = parx;
                size[parx] += size[pary];
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
                int x, y;
                cin >> x >> y;
                if (ds.find(x) == ds.find(y))
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
            else
            {
                int x, y;
                cin >> x >> y;
                ds.unionByRank(x, y);
            }
        }
    }
}