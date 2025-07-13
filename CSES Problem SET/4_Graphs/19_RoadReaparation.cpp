#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (Union-Find)
class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find_set(int x) {
        if (parent[x] != x)
            parent[x] = find_set(parent[x]);
        return parent[x];
    }

    void union_set(int x, int y) {
        x = find_set(x);
        y = find_set(y);
        if (x == y) return;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(c, a, b); // Store as (cost, u, v)
    }

    // Sort edges by cost
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    long long total_cost = 0;
    int edges_used = 0;

    for (auto [cost, u, v] : edges) {
        if (dsu.find_set(u) != dsu.find_set(v)) {
            dsu.union_set(u, v);
            total_cost += cost;
            edges_used++;
        }
    }

    if (edges_used == n - 1)
        cout << total_cost << "\n";
    else
        cout << "IMPOSSIBLE\n";

    return 0;
}
