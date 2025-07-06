#include <bits/stdc++.h>
using namespace std;
#define int long long int

class DSU
{
    int count;
    vector<int> par;
    vector<int> size;
    int maxSize;

public:
    DSU(int n)
    {
        count = n;
        par.resize(n + 1);
        for (int i = 1; i <= n; i++)
            par[i] = i;
        size.resize(n + 1, 1);
        maxSize = 1;
    }

    int find(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }

    void unionn(int x, int y)
    {
        int parx = find(x), pary = find(y);
        if (parx != pary)
        {
            count -= 1;
            if (size[parx] > size[pary])
            {
                size[parx] += size[pary];
                par[pary] = parx;
                maxSize = max(maxSize, size[parx]);
            }
            else
            {
                size[pary] += size[parx];
                par[parx] = pary;
                maxSize = max(maxSize, size[pary]);
            }
        }
        cout << count << " " << maxSize << endl;
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    DSU ds(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        ds.unionn(x, y);
    }
}
#undef int
int main()
{
    solve();
}