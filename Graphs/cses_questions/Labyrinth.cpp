#include <bits/stdc++.h>
using namespace std;
#define int long long

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
        pair<int, int> start, dest;

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
                if (v[i][j] == 'B')
                    dest = {i, j};
            }
        }

        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();

            if (r == dest.first && c == dest.second)
                break;

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

        if (!vis[dest.first][dest.second])
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

#undef int
int main()
{
    Solution sol;
    sol.solve();
}
