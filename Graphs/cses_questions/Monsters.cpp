#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> dr = {-1, 0, 1, 0}, dc = {0, -1, 0, 1};
    vector<char> dir = {'U', 'L', 'D', 'R'};

public:
    void solve()
    {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        for (auto &row : v)
            cin >> row;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
        vector<vector<char>> move(n, vector<char>(m));

        queue<pair<int, int>> q;
        pair<int, int> start, dest = {-1, -1};
        set<pair<int, int>> mon;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == 'A')
                {
                    start = {i, j};
                    q.push({i, j});
                    vis[i][j] = 1;
                }
                if (v[i][j] == 'M')
                    mon.insert({i, j});
            }
        }

        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();

            if (mon.find({r, c}) != mon.end())
                continue;
            if (r == 0 || c == 0 || r == n - 1 || c == m - 1)
            {
                dest = {r, c};
                break;
            }

            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    !vis[nr][nc] && v[nr][nc] != '#')
                {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                    parent[nr][nc] = {r, c};
                    move[nr][nc] = dir[i];
                }
            }
        }

        if (dest.first == -1)
        {
            cout << "NO\n";
            return;
        }

        string path = "";
        pair<int, int> curr = dest;
        while (curr != start)
        {
            char d = move[curr.first][curr.second];
            path += d;
            curr = parent[curr.first][curr.second];
        }
        reverse(path.begin(), path.end());

        cout << "YES\n";
        cout << path.size() << '\n';
        cout << path << '\n';
    }
};

int main()
{
    Solution sol;
    sol.solve();
}
