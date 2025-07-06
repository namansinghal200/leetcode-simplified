#include <bits/stdc++.h>
using namespace std;
#define int long long int
class DSU
{
    vector<int> par, rank;

public:
    DSU(int n)
    {
        par.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
            rank[i] = 1;
        }
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
};
class Solution
{
public:
    static bool cmp(vector<int> &v1, vector<int> &v2)
    {
        return v1[2] < v2[2];
    }
    int kruskalsMST(int V, vector<vector<int>> &edges)
    {
        // code here
        sort(edges.begin(), edges.end(), cmp);
        DSU ds(V + 1);
        int ans = 0, count = 0;

        for (auto i : edges)
        {
            int par1 = ds.find(i[0]);
            int par2 = ds.find(i[1]);
            if (par1 != par2)
            {
                ans += i[2];
                count++;
                ds.unionn(i[0], i[1]);
                if (count == V - 1)
                    return ans;
            }
        }
        return -1;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> edges[i][j];
        }
    }
    // for (auto i : edges)
    // {
    //     cout << i[0] << " " << i[1] << " " << i[2] << endl;
    // }
    Solution krus;
    auto ans = krus.kruskalsMST(n, edges);
    if (ans == -1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
        cout << ans << endl;
}
#undef int
int main()
{

    solve();
}