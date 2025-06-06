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
        int n, m, q;
        cin >> n >> m >> q;
        DSU ds(n + 1);
        vector<pair<string, pair<int, int>>> v;
        set<pair<int, int>> st;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            st.insert({x, y});
        }
        for (int i = 0; i < q; i++)
        {
            string s;
            int x, y;
            cin >> s >> x >> y;
            v.push_back({s, {x, y}});
            if (s == "cut")
            {
                st.erase({x, y});
                st.erase({y, x});
            }
        }

        for (auto i : st)
        {
            ds.unionBySize(i.first, i.second);
        }
        // for (auto i : ds.par)
        //     cout << i << " ";
        vector<string> ans;
        for (int i = q - 1; i >= 0; i--)
        {
            if (v[i].first == "ask")
            {
                if (ds.find(v[i].second.first) == ds.find(v[i].second.second))
                {
                    ans.push_back("YES");
                }
                else
                {
                    ans.push_back("NO");
                }
            }
            else
            {
                ds.unionBySize(v[i].second.first, v[i].second.second);
            }
        }
        reverse(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << endl;
    }
}