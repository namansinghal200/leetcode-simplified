#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int

class Solution
{

public:
    void solve()
    {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> adj(n + 1);

        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            adj[x].push_back({y, z});
        }

        vector<int> dp(n + 1, LLONG_MAX), cnt(n + 1, 0), mini(n + 1, LLONG_MAX), maxi(n + 1, LLONG_MIN);
        dp[1] = 0, cnt[1] = 1, mini[1] = 0, maxi[1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        while (!pq.empty())
        {
            int dis = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (dis > dp[u])
                continue;

            for (auto i : adj[u])
            {
                if (dp[i.first] > dp[u] + i.second)
                {
                    dp[i.first] = dp[u] + i.second;
                    cnt[i.first] = cnt[u];
                    mini[i.first] = mini[u] + 1;
                    maxi[i.first] = maxi[u] + 1;
                    pq.push({dp[i.first], i.first});
                }
                else if (dp[i.first] == dp[u] + i.second)
                {
                    cnt[i.first] = (cnt[u] + cnt[i.first]) % mod;
                    mini[i.first] = min(mini[i.first], mini[u] + 1);
                    maxi[i.first] = max(maxi[u] + 1, maxi[i.first]);
                }
            }
        }
        cout << dp[n] << " " << cnt[n] << " " << mini[n] << " " << maxi[n] << endl;

        return;
    }
};

#undef int
int main()
{
    Solution sol;
    sol.solve();
}