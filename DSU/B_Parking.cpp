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

    void unionn(int x)
    {
        int parx = find(x);
        par[parx] = (parx + 1) % par.size();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        DSU ds(n);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            cout << ds.find(x - 1) + 1 << " ";
            ds.unionn(x - 1);
        }
    }
    return 0;
}
