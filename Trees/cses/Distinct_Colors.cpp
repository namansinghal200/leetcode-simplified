#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

const int MAXN = 200005;

struct Query
{
    int start_time, end_time, original_node_idx;
};

// Global variables with descriptive names
int n;
int colors[MAXN];
std::vector<int> adj[MAXN];
int entry_time[MAXN], exit_time[MAXN];
int timer = 0;

// Fenwick Tree (BIT) for counting
long long fenwick_tree[2 * MAXN];

void bit_update(int idx, int delta)
{
    for (; idx <= 2 * n; idx += idx & -idx)
    {
        fenwick_tree[idx] += delta;
    }
}

long long bit_query(int idx)
{
    long long sum = 0;
    for (; idx > 0; idx -= idx & -idx)
    {
        sum += fenwick_tree[idx];
    }
    return sum;
}

void dfs_timer(int u = 1, int p = 0)
{
    entry_time[u] = ++timer;
    for (int v : adj[u])
    {
        if (v != p)
        {
            dfs_timer(v, u);
        }
    }
    exit_time[u] = ++timer;
}

int main()
{
    // Use fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> colors[i];
    }

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Step 1: Flatten tree with DFS to get time ranges for subtrees
    dfs_timer();

    // Create a flattened array `flat_events` where events are colors appearing at entry/exit times
    std::vector<int> flat_events(2 * n + 1);
    for (int i = 1; i <= n; ++i)
    {
        flat_events[entry_time[i]] = colors[i];
    }

    std::vector<int> next_occurrence(2 * n + 1, 0);
    std::map<int, int> last_seen_at;

    // Step 2: Pre-compute next occurrences
    for (int i = 2 * n; i >= 1; --i)
    {
        if (flat_events[i] != 0)
        { // Only consider actual events
            if (last_seen_at.count(flat_events[i]))
            {
                next_occurrence[i] = last_seen_at[flat_events[i]];
            }
            last_seen_at[flat_events[i]] = i;
        }
    }

    // Initialize BIT: Mark only the first occurrence of each color
    for (auto const &[color, index] : last_seen_at)
    {
        bit_update(index, 1);
    }

    // Step 3: Prepare and sort queries
    std::vector<Query> queries(n);
    for (int i = 1; i <= n; ++i)
    {
        queries[i - 1] = {entry_time[i], exit_time[i], i};
    }
    std::sort(queries.begin(), queries.end(), [](const Query &q1, const Query &q2)
              { return q1.start_time < q2.start_time; });

    // Step 4: Sweep-line algorithm
    std::vector<int> answers(n + 1);
    int sweep_ptr = 1;
    for (const auto &q : queries)
    {
        while (sweep_ptr < q.start_time)
        {
            // Deactivate current color occurrence, activate the next one
            if (next_occurrence[sweep_ptr] != 0)
            {
                bit_update(next_occurrence[sweep_ptr], 1);
            }
            sweep_ptr++;
        }
        answers[q.original_node_idx] = bit_query(q.end_time) - bit_query(q.start_time - 1);
    }

    for (int i = 1; i <= n; ++i)
    {
        std::cout << answers[i] << (i == n ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}