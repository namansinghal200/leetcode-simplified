#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    vector<int> par;

public:
    DSU(int n)
    {
        par.resize(n + 1);
        for (int i = 0; i <= n; i++)
            par[i] = i;
    }
    int find(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }
    void unionn(int x, int y)
    {
        int parx = find(x);
        int pary = find(y);
        if (parx == pary)
            return;
        par[pary] = parx;
    }
    vector<int> components()
    {
        vector<int> ans;
        for (int i = 1; i < (int)par.size(); i++)
        {
            if (par[i] == i)
                ans.push_back(i);
        }
        return ans;
    }
};
class Solution
{

public:
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
        vector<int> getCmp = ds.components();
        cout << getCmp.size() - 1 << endl;
        for (int i = 0; i < (int)getCmp.size() - 1; i++)
        {
            cout << getCmp[i] << " " << getCmp[i + 1] << endl;
        }
    }
};
int main()
{
    Solution sol;
    sol.solve();
}