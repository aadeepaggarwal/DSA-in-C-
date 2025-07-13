#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge {
    int v, weight;
};

vector<int> dijkstra(int x, int n, vector<vector<Edge>> &adj) {
    vector<int> distance(n + 1, INF);
    vector<bool> processed(n + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

    distance[x] = 0;
    q.push({0, x});

    while (!q.empty()) {
        int a = q.top().second;
        q.pop();
        if (processed[a]) continue;
        processed[a] = true;

        for (auto u : adj[a]) {
            int b = u.v, w = u.weight;
            if (distance[b] > distance[a] + w) {
                distance[b] = distance[a] + w;
                q.push({distance[b], b});
            }
        }
    }

    return distance;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n + 1), radj(n + 1);
    vector<array<int, 3>> edges;

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        radj[b].push_back({a, w}); // Reverse edge
        edges.push_back({a, b, w});
    }

    auto distS = dijkstra(1, n, adj);  // From source (1)
    auto distD = dijkstra(n, n, radj); // To destination (n) using reverse graph

    int res = distS[n]; // Initial result without using discount
    for (auto e : edges) {
        int u = e[0], v = e[1], w = e[2];
        if (distS[u] != INF && distD[v] != INF) {
            res = min(res, distS[u] + (w / 2) + distD[v]);
        }
    }

    cout << res << endl;
    return 0;
}
